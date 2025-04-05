#include "weatherapiclient.h"

WeatherApiClient::WeatherApiClient(QObject *parent, QString zipCode_, QString countryCode_) : QObject(parent)
{
    zipCode = zipCode_;
    countryCode = countryCode_;
    manager = new QNetworkAccessManager(this);
    checkInternetConnection();
}

QJsonObject WeatherApiClient::getWeatherJsonData()
{
    QString url = QString("https://api.openweathermap.org/data/2.5/weather?zip=%1,%2&appid=%3").arg(zipCode).arg(countryCode).arg(apiKey);
    url = "http://api.weatherapi.com/v1/current.json?key=3467533238ac4236821131358250504&q=London&aqi=yes";
    qDebug() << url;
    QNetworkRequest request((QUrl(url)));

    reply = manager->get(request);
//    connect(reply, &QNetworkReply::finished, this, &WeatherApiClient::onWeatherDataReceived);
    connect(reply, &QNetworkReply::finished, [this]() {
        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << "Error: " << reply->errorString();
            reply->deleteLater();
            return;
        }
        QByteArray responseData = reply->readAll();
        qDebug() << responseData;
        reply->deleteLater();
    });


    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "No Data Found";
        return {};
    }
    return weatherJsonData;
}

void WeatherApiClient::onWeatherDataReceived()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonParseError error;
        QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData, &error);
        if (error.error != QJsonParseError::NoError) {
            qDebug() << "Ошибка парсинга Json: " << error.errorString();
            weatherJsonData = {};
            return;
        }
        if (!jsonDocument.isObject()) {
            qDebug() << "Json не является объектом";
            weatherJsonData = {};
            return;
        }
        qDebug() << jsonDocument.toJson(QJsonDocument::Indented);
        weatherJsonData = jsonDocument.object();
    } else {
        qDebug() << "Error: " << reply->errorString();
    }
    reply->deleteLater();
}

void WeatherApiClient::checkInternetConnection() {
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request(QUrl("http://www.google.com"));
    QNetworkReply *reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            qDebug() << "Соединение с интернетом установлено";
        } else {
            qDebug() << "Соединение с интернетом отсутствует";
        }
        reply->deleteLater();
    });
}
