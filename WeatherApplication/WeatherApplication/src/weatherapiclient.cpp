#include "weatherapiclient.h"

WeatherApiClient::WeatherApiClient(QObject *parent, QString zipCode_, QString countryCode_) : QObject(parent)
{
    manager = new QNetworkAccessManager(this);
}

void WeatherApiClient::slotFindCityData(const QString &city)
{
    QString url = QString("https://api.openweathermap.org/geo/1.0/direct?q=%1&appid=%2").arg(city).arg(apiKey);
    qDebug() << url;
    QNetworkRequest request((QUrl(url)));
    replyCity = manager->get(request);
    connect(replyCity, &QNetworkReply::finished, this, &WeatherApiClient::onSlotFindCityData);
    return;
}

void WeatherApiClient::onSlotFindCityData()
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
            QJsonObject jsonError;
            jsonError["error"] = "Ошибка парсинга Json при поиске города: " +  error.errorString();
            emit recivedWeatherData({jsonError});
            return;
        }
        if (!jsonDocument.isArray()) {
            qDebug() << "Json не является массивом";
            QJsonObject jsonError;
            jsonError["error"] = "Json не является массивом";
            emit recivedWeatherData({jsonError});
            return;
        }
        QJsonArray jsonArray = jsonDocument.array();
        if (jsonArray.isEmpty()) {
            qDebug() << "Город не найден";
            QJsonObject jsonError;
            jsonError["error"] = "Город не найден";
            emit recivedWeatherData({jsonError});
            return;
        }
        QJsonObject cityData = jsonArray[0].toObject();
        QString lat = QString::number(cityData["lat"].toDouble());
        QString lon = QString::number(cityData["lon"].toDouble());

        qDebug() << "Lat:" << lat << "Lon:" << lon;
        findWeatherData(lat, lon);
    } else {
        qDebug() << "Error: " << reply->errorString();
        QJsonObject jsonError;
        jsonError["error"] = "Error: " + reply->errorString();
        emit recivedWeatherData({jsonError});
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
            QJsonObject jsonError;
            jsonError["error"] = "Ошибка парсинга Json при поиске погоды: "  +  error.errorString();
            emit recivedWeatherData({jsonError});
            return;
        }
        if (!jsonDocument.isObject()) {
            qDebug() << "Json не является объектом";
            QJsonObject jsonError;
            jsonError["error"] = "Json не является массивом";
            emit recivedWeatherData({jsonError});
            return;
        }
        // qDebug() << jsonDocument.toJson(QJsonDocument::Indented);
        weatherJsonData = jsonDocument.object();
        if (weatherJsonData.isEmpty()) {
            qDebug() << "Погода не найден";
            QJsonObject jsonError;
            jsonError["error"] = "Погода не найден";
            emit recivedWeatherData({jsonError});
            return;
        }
        emit recivedWeatherData(weatherJsonData);
    } else {
        qDebug() << "Error: " << reply->errorString();
        QJsonObject jsonError;
        jsonError["error"] = "Error: " + reply->errorString();
        emit recivedWeatherData({jsonError});
        return;
    }
    reply->deleteLater();
    return;
}

void WeatherApiClient::findWeatherData(const QString &lat, const QString &lon)
{
    QString url = QString("https://api.openweathermap.org/data/2.5/forecast?lat=%1&lon=%2&appid=%3&units=metric&lang=ru").arg(lat).arg(lon).arg(apiKey);
    qDebug() << url;
    QNetworkRequest request((QUrl(url)));
    replyWeather = manager->get(request);
    connect(replyWeather, &QNetworkReply::finished, this, &WeatherApiClient::onSlotFindWeatherData);
    return;
}

