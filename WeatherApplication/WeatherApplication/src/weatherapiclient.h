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

public slots:
    void slotCountryChange(const QString &zipCode, const QString &countryCode);

private slots:
    void onWeatherDataReceived();

private:
    const QString apiKey = "42742ea2be4d089818ddf4c59fd721be";
    QNetworkAccessManager *manager;
    QNetworkReply *reply;

signals:
    void jsonDataReceivedFromAPI(const QJsonObject &jsonObj);
};

#endif // WEATHERAPICLIENT_H

