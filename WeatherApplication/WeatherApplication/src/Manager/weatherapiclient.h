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
#include <QJsonArray>
#include "../Models/apireply.h"

class WeatherApiClient : public QObject
{
    Q_OBJECT
public:
    explicit WeatherApiClient(QObject *parent = nullptr);
    void findWeatherDataInAPI(const QString &city);
    bool loadConfig(const QJsonObject &jsonObj);

private slots:
    void onSlotFindCity();
    void onSlotFindWeatherData();

private:
    QString apiKey;
    QString urlFindCityByName;
    QString urlFindWeatherByCoordinates;

    QNetworkAccessManager *manager;
    QNetworkReply *replyCity;
    QNetworkReply *replyWeather;

    ApiReply createErroneousResponse(const QString &message);

    void findWeatherData(const QString &lat, const QString &lon);

signals:
    void sendRecivedWeatherDataFromAPI(const ApiReply &data);
};

#endif // WEATHERAPICLIENT_H

