#include "weatherapiclient.h"

WeatherApiClient::WeatherApiClient(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager(this);
}

void WeatherApiClient::findWeatherDataInAPI(const QString &city)
{

    QString url = QString(urlFindCityByName).arg(city).arg(apiKey);
    qDebug() << url;
    QNetworkRequest request((QUrl(url)));
    replyCity = manager->get(request);
    connect(replyCity, &QNetworkReply::finished, this, &WeatherApiClient::onSlotFindCity);
    return ;
}

bool WeatherApiClient::loadConfig(const QJsonObject &settingsAPI)
{
    if (settingsAPI.contains("api") && settingsAPI["api"].isObject() && settingsAPI.contains("key")) {
        apiKey = settingsAPI["api"].toObject()["key"].toString();
        if (settingsAPI.contains("urlFindCityByName") && settingsAPI.contains("urlFindWeatherByCoordinates")) {
            urlFindCityByName = settingsAPI["api"].toObject()["urlFindCityByName"].toString();
            urlFindWeatherByCoordinates = settingsAPI["api"].toObject()["urlFindWeatherByCoordinates"].toString();
            return true;
        } else {
            qDebug("Нет нужных элементо в JSON");
            return false;
        }
    }
    return false;
}

void WeatherApiClient::onSlotFindCity()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if (!reply) {
        qDebug() << "Invalid reply";
        return;
    }
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonParseError error;
        QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData, &error);
        if (error.error != QJsonParseError::NoError) {
            qDebug() << "Ошибка парсинга Json при поиске города: " << error.errorString();
            emit sendRecivedWeatherDataFromAPI({});
            return;
        }
        if (!jsonDocument.isArray()) {
            qDebug() << "Json не является массивом";
            emit sendRecivedWeatherDataFromAPI({});
            return;
        }
        QJsonArray jsonArray = jsonDocument.array();
        if (jsonArray.isEmpty()) {
            qDebug() << "Город не найден";
            emit sendRecivedWeatherDataFromAPI({});
            return;
        }
        QJsonObject cityData = jsonArray[0].toObject();
        QString lat = QString::number(cityData["lat"].toDouble());
        QString lon = QString::number(cityData["lon"].toDouble());
        findWeatherData(lat, lon);
    } else {
        qDebug() << "Error: " << reply->errorString();
        emit sendRecivedWeatherDataFromAPI({});
        return;
    }
    reply->deleteLater();
    return;
}

void WeatherApiClient::onSlotFindWeatherData()
{

    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if (!reply) {
        qDebug() << "Invalid reply";
        return;
    }
    QJsonObject weatherJsonData;
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonParseError error;
        QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData, &error);
        if (error.error != QJsonParseError::NoError) {
            qDebug() << "Ошибка парсинга Json при поиске погоды: " << error.errorString();
            emit sendRecivedWeatherDataFromAPI({});
            return;
        }
        if (!jsonDocument.isObject()) {
            qDebug() << "Json не является объектом";
            emit sendRecivedWeatherDataFromAPI({});
            return;
        }
        weatherJsonData = jsonDocument.object();
        if (weatherJsonData.isEmpty()) {
            qDebug() << "Погода не найден";
            emit sendRecivedWeatherDataFromAPI({});
            return;
        }
        emit sendRecivedWeatherDataFromAPI(weatherJsonData);
    } else {
        qDebug() << "Error: " << reply->errorString();
        emit sendRecivedWeatherDataFromAPI({});
        return;
    }
    reply->deleteLater();
    return;
}

void WeatherApiClient::findWeatherData(const QString &lat, const QString &lon)
{
    QString url = QString(urlFindWeatherByCoordinates).arg(lat).arg(lon).arg(apiKey);
    qDebug() << url;
    QNetworkRequest request((QUrl(url)));
    replyWeather = manager->get(request);
    connect(replyWeather, &QNetworkReply::finished, this, &WeatherApiClient::onSlotFindWeatherData);
    return;
}

