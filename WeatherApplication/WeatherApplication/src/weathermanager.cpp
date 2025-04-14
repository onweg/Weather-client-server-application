#include "weathermanager.h"

WeatherManager::WeatherManager(QObject *parent) : QObject(parent)
{
    networkManager = new QNetworkAccessManager(this);
    QObject::connect(networkManager, &QNetworkAccessManager::finished, this, &WeatherManager::onReplyFinished);
    QObject::connect(&api, &WeatherApiClient::sendRecivedWeatherDataFromAPI, this, &WeatherManager::slotRecivedWeatherDataFromAPI);

    cacheCleaner = new CacheCleaner();
    cleanerThread = new QThread(this);

    QObject::connect(cleanerThread, &QThread::started, cacheCleaner, &CacheCleaner::start);
    QObject::connect(cacheCleaner, &CacheCleaner::timeout, &cache, &WeatherCache::clearExpired);
    QObject::connect(cleanerThread, &QThread::finished, cleanerThread, &QThread::deleteLater);

    cacheCleaner->moveToThread(cleanerThread);
    cleanerThread->start();

}

WeatherManager::~WeatherManager()
{
    if (cleanerThread) {
        cleanerThread->quit();
        cleanerThread->wait();
        delete cleanerThread;
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
        api.findWeatherDataInAPI(desiredCity);
    }

}

void WeatherManager::slotRecivedWeatherDataFromAPI(const QJsonObject &jsonObj)
{
    QJsonObject correctJsonData = dataEditor.getCorrectData(jsonObj);
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

