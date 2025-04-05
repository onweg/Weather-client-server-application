#ifndef WEATHERAPICLIENT_H
#define WEATHERAPICLIENT_H

// общается с внешним API через Http протокол
// получает данные в виде JSON формата
// Обрабатывает ошибки

#include <QObject>
#include <QString>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QByteArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonParseError>

class WeatherApiClient : public QObject
{
    Q_OBJECT
public:
    explicit WeatherApiClient(QObject *parent = nullptr, QString zipCode_ = "101000", QString countryCode_ = "RU");
    QJsonObject getWeatherJsonData();

private slots:
    void onWeatherDataReceived();

private:
    QString zipCode, countryCode;
    const QString apiKey = "3467533238ac4236821131358250504";
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QJsonObject weatherJsonData;


    void checkInternetConnection();
;
signals:

};

#endif // WEATHERAPICLIENT_H
