#include "weathermanager.h"

WeatherManager::WeatherManager(QObject *parent) : QObject(parent)
{
    api = new WeatherApiClient(this);

    networkManager = new QNetworkAccessManager(this);
    QObject::connect(networkManager, &QNetworkAccessManager::finished, this, &WeatherManager::onReplyFinished);
    QObject::connect(api, &WeatherApiClient::sendRecivedWeatherDataFromAPI, this, &WeatherManager::slotRecivedWeatherDataFromAPI);

    cacheCleaner = new CacheCleaner();
    cleanerThread.reset(new QThread());

    QObject::connect(cleanerThread.data(), &QThread::started, cacheCleaner, &CacheCleaner::start);
    QObject::connect(cacheCleaner, &CacheCleaner::timeout, &cache, &WeatherCache::clearExpired);

    cacheCleaner->moveToThread(cleanerThread.data());
    cleanerThread->start();

}

WeatherManager::~WeatherManager()
{
    if (cleanerThread) {
        cleanerThread->quit();
        cleanerThread->wait();
    }
    delete cacheCleaner;
    cacheCleaner = nullptr;
}

void WeatherManager::slotFindWeatherData(const QString &city, const QDate &date)
{
    desiredCity = city;
    desiredDate = date;
    int status = cache.hasValidData(desiredCity, desiredDate);
    if (status == 0) {
        emit sendWeatherDataToController(cache.getData(desiredCity, desiredDate));
    } else if (status == 1){
        api->findWeatherDataInAPI(desiredCity);
    }

}

void WeatherManager::slotRecivedWeatherDataFromAPI(const QJsonObject &jsonObj)
{
    QJsonObject correctJsonData = WeatherJsonConverter::getCorrectData(jsonObj);
    QJsonDocument doc2(correctJsonData);
    qDebug().noquote() << doc2.toJson(QJsonDocument::Indented);
    if (correctJsonData.isEmpty()) {
        QJsonObject error;
        error["error"] = "Город не найден!";
        emit sendWeatherDataToController(error);

    } else {
        cache.addData(desiredCity, correctJsonData);

        QJsonObject tmp = cache.getData(desiredCity, desiredDate);
        tmp["city"] = correctJsonData["city"].toString();
        tmp["date"] = desiredDate.toString("yyyy-MM-dd");
        QJsonDocument doc(tmp);
        qDebug().noquote() << doc.toJson(QJsonDocument::Indented);
        emit sendWeatherDataToController(tmp);
        emit submitCompletedWeatherDataSearchRequest(user, tmp["city"].toString(), desiredDate);
    }

}

void WeatherManager::sloRecivedAuthorizationData(const QString &command, const QString &login, const QString &password)
{
    user = login;
    QUrl url("http://10.42.0.227:33333");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["command"] = command;
    json["login"] = login;
    json["password"] = password;

    QJsonDocument doc(json);
    qDebug().noquote() << doc.toJson(QJsonDocument::Indented);
    QByteArray data = doc.toJson();

    networkManager->post(request, data);
}

void WeatherManager::slotFindWeekWeatherData()
{
    QDate tmpDate = QDate::currentDate();
    QJsonObject weekData;
    weekData["city"] = desiredCity;
    for (int index_day = 0; index_day < 5; index_day++) {
        int status = cache.hasValidData(desiredCity);
        if (status != 0) {
            return;
        }
        QJsonObject tmpDayData = cache.getData(desiredCity, tmpDate);
//        QJsonDocument doc2(tmpDayData);
//        qDebug().noquote() << doc2.toJson(QJsonDocument::Indented);
        QJsonObject tmp;
        tmp["date"] = tmpDayData["date"].toString();
        tmp["temp"] = QString::number(tmpDayData["temp"].toDouble());
        weekData[QString::number(index_day)] = tmp;
        tmpDate = tmpDate.addDays(1);
    }
//    QJsonDocument doc(weekData);
//    qDebug().noquote() << doc.toJson(QJsonDocument::Indented);
    emit sendWeekWeatherDataToController(weekData);
}

bool WeatherManager::loadConfig()
{
    QString filePath = QCoreApplication::applicationDirPath();
    qDebug() << filePath;
    QFile file("/usr/share/ru.auroraos.WeatherApplication/config/api_config.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Не удалось открыть api_config.json файл";
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
    settingsAPI = doc.object();
    return api->loadConfig(settingsAPI);
}

void WeatherManager::onReplyFinished(QNetworkReply *reply)
{
    QByteArray responseData = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(responseData);
    if (!doc.isNull() && doc.isObject()) {
        QJsonObject jsonObj = doc.object();
        emit sendAuthorizationResult(jsonObj);

    } else {
        qDebug() << "Некорректный Json файл!";
    }
}


