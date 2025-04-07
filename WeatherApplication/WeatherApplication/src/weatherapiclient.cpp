#include "weatherapiclient.h"

WeatherApiClient::WeatherApiClient(QObject *parent, QString zipCode_, QString countryCode_) : QObject(parent)
{
    manager = new QNetworkAccessManager(this);
}

void WeatherApiClient::slotCountryChange(const QString &zipCode, const QString &countryCode)
{
    QString url = QString("https://api.openweathermap.org/data/2.5/weather?zip=%1,%2&appid=%3").arg(zipCode).arg(countryCode).arg(apiKey);
    qDebug() << url;
    QNetworkRequest request((QUrl(url)));

    reply = manager->get(request);
    connect(reply, &QNetworkReply::finished, this, &WeatherApiClient::onWeatherDataReceived);

    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "No Data Found";
        return ;
    }
    return;
}

void WeatherApiClient::onWeatherDataReceived()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    QJsonObject weatherJsonData;
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
        // qDebug() << jsonDocument.toJson(QJsonDocument::Indented);
        weatherJsonData = jsonDocument.object();
    } else {
        qDebug() << "Error: " << reply->errorString();
    }
    emit jsonDataReceivedFromAPI(weatherJsonData);
    reply->deleteLater();
}

