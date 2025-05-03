#include "WeatherManager.h"

WeatherManager::WeatherManager(QObject *parent) : QObject(parent)
{
    api_ = new WeatherApiClient(this);

    networkManager_ = new QNetworkAccessManager(this);
    QObject::connect(networkManager_, &QNetworkAccessManager::finished, this, &WeatherManager::onReplyFinished);
    QObject::connect(api_, &WeatherApiClient::sendRecivedWeatherDataFromAPI, this, &WeatherManager::slotRecivedWeatherDataFromAPI);

    cacheCleaner_ = new CacheCleaner();
    cleanerThread_.reset(new QThread());

    QObject::connect(cleanerThread_.data(), &QThread::started, cacheCleaner_, &CacheCleaner::start);
    QObject::connect(cacheCleaner_, &CacheCleaner::timeout, &cache_, &WeatherCache::clearExpired);

    cacheCleaner_->moveToThread(cleanerThread_.data());
    cleanerThread_->start();

}

WeatherManager::~WeatherManager()
{
    if (cleanerThread_) {
        cleanerThread_->quit();
        cleanerThread_->wait();
    }
    delete cacheCleaner_;
    cacheCleaner_ = nullptr;
}

void WeatherManager::slotFindWeatherData(const QString &city, const QDate &date)
{
    desiredCity_ = city;
    desiredDate_ = date;
    int status = cache_.hasValidData(desiredCity_, desiredDate_);
    if (status == 0) {
        emit sendWeatherDataToController(cache_.getWeatherData(desiredCity_, desiredDate_));
    } else if (status == 1 || status == 3){
        api_->findWeatherDataInAPI(desiredCity_);
    }
    addDataToDatabase();
}

void WeatherManager::slotRecivedWeatherDataFromAPI(const ApiReply &response)
{
    if (!response.success) {
        WeatherData error;
        error.messageError = response.messageError;
        emit sendWeatherDataToController(error);
    } else {
        WeekWeatherData weatherData = WeatherJsonConverter::parseWeekWeather(response.data);
        cache_.addData(desiredCity_, weatherData);
        WeatherData dataResult = cache_.getWeatherData(desiredCity_, desiredDate_);
        emit sendWeatherDataToController(dataResult);
    }
}


void WeatherManager::sloRecivedAuthorizationData(const AuthorizationInfo &info)
{
    user_ = info.login;
    QString urlStr = "http://" + serverHostConfig_.ip + ":" + serverHostConfig_.port;
    QUrl url(urlStr);
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = AuthorizationInfoJsonConverter::toJsonDocument(info).toJson();
    networkManager_->post(request, data);
}

void WeatherManager::slotFindWeekWeatherData()
{
    WeekWeatherData weekWeatherData = cache_.getWeekWeatherData(desiredCity_);
    emit sendWeekWeatherDataToController(weekWeatherData);
}

bool WeatherManager::loadConfig()
{
    QFile file("/usr/share/ru.auroraos.WeatherApplication/config/config.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Не удалось открыть config.json файл";
        return false;
    }
    QByteArray jsonData = file.readAll();
    file.close();
    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(jsonData, &parseError);
    if (parseError.error != QJsonParseError::NoError) {
        qDebug() << "Ошибка парсинга json файла";
        return false;
    }
    AppConfig appConfig;
    if (AppConfigJsonConverter::fromJson(doc.object(), appConfig) == false) {
        return false;
    }
    serverHostConfig_ = appConfig.serverHostConfig;
    ApiConfig apiConfig = appConfig.apiConfig;
    if (api_->loadConfig(apiConfig) == false) {
        return false;
    }
    return true;
}

void WeatherManager::addDataToDatabase()
{
    WeatherHistoryItem weatherHistoryItem;
    weatherHistoryItem.city = desiredCity_;
    weatherHistoryItem.date = desiredDate_;
    weatherHistoryItem.username = user_;
    emit submitCompletedWeatherDataSearchRequest(weatherHistoryItem);
}

void WeatherManager::onReplyFinished(QNetworkReply *reply)
{
    QByteArray responseData = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(responseData);
    QJsonObject jsonObj = doc.object();
    AuthorizationReply authorizationReply = AuthorizationReplyJsonConverter::parseAuthorizationReply(jsonObj);
     emit sendAuthorizationResult(authorizationReply);

}


