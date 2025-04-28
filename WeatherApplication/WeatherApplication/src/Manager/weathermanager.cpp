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
        emit sendWeatherDataToController(cache.getWeatherData(desiredCity, desiredDate));
    } else if (status == 1 || status == 3){
        api->findWeatherDataInAPI(desiredCity);
    }

}

void WeatherManager::slotRecivedWeatherDataFromAPI(const ApiReply &response)
{
    // QJsonDocument doc2(correctJsonData);
    // qDebug().noquote() << doc2.toJson(QJsonDocument::Indented);
    if (!response.success) {
        WeatherData error;
        error.messageError = response.messageError;
        emit sendWeatherDataToController(error);
    } else {
        WeekWeatherData weatherData = WeatherJsonConverter::parseWeekWeather(response.data);
        qDebug() << weatherData.city << "               QWEQWEQWEWQEWEQWEQWEQWEQWEWEQWEQWEQWEQWE";
        cache.addData(desiredCity, weatherData);
        WeatherData dataResult = cache.getWeatherData(desiredCity, desiredDate);
        // tmp["city"] = correctJsonData["city"].toString();
        // tmp["date"] = desiredDate.toString("yyyy-MM-dd");
        // QJsonDocument doc(tmp);
        // qDebug().noquote() << doc.toJson(QJsonDocument::Indented);
        qDebug() << dataResult.city << "               QWEQWEQWEWQEWEQWEQWEQWEQWEWEQWEQWEQWEQWE";
        emit sendWeatherDataToController(dataResult);
        emit submitCompletedWeatherDataSearchRequest(user, dataResult.city, desiredDate);
    }

}

void WeatherManager::sloRecivedAuthorizationData(const QString &command, const QString &login, const QString &password)
{
    user = login;
    QString urlStr = "http://" + serverHost.ip + ":" + serverHost.port;
    QUrl url(urlStr);
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
    // QDate tmpDate = QDate::currentDate();
    WeekWeatherData weekWeatherData = cache.getWeekWeatherData(desiredCity);
//     for (int index_day = 0; index_day < 5; index_day++) {
//         int status = cache.hasValidData(desiredCity);
//         if (status != 0) {
//             return;
//         }
//         QJsonObject tmpDayData = cache.getData(desiredCity, tmpDate);
// //        QJsonDocument doc2(tmpDayData);
// //        qDebug().noquote() << doc2.toJson(QJsonDocument::Indented);
//         QJsonObject tmp;
//         tmp["date"] = tmpDayData["date"].toString();
//         tmp["temp"] = QString::number(tmpDayData["temp"].toDouble());
//         weekData[QString::number(index_day)] = tmp;
//         tmpDate = tmpDate.addDays(1);
//     }
//    QJsonDocument doc(weekData);
//    qDebug().noquote() << doc.toJson(QJsonDocument::Indented);
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
    QJsonObject config = doc.object();
    if (!config.contains("server host")) {
        qDebug() << "В config файле нет настроек хоста сервера";
        return false;
    } else {
        QJsonObject serverHostObj = config["server host"].toObject();
        if (serverHostObj.contains("ip") && serverHostObj.contains("port")) {
            serverHost.ip = serverHostObj["ip"].toString();
            serverHost.port = serverHostObj["port"].toString();
        } else {
            qDebug() << "В config файле нет настроек хоста сервера";
            return false;
        }
    }
    if (!(config.contains("api") && api->loadConfig(config["api"].toObject()))) {
        qDebug() << "В config файле нет настроек api";
        return false;
    }

    return true;
}

void WeatherManager::onReplyFinished(QNetworkReply *reply)
{
    QByteArray responseData = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(responseData);
    // if (!doc.isNull() && doc.isObject()) {
        QJsonObject jsonObj = doc.object();
        AuthorizationReply authorizationReply = WeatherJsonConverter::parseAuthorizationReply(jsonObj);
        emit sendAuthorizationResult(authorizationReply);
    // } else {
    //     qDebug() << "Некорректный Json файл!";
    // }
}


