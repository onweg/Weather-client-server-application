#ifndef CLIENTCONTROLLER_H
#define CLIENTCONTROLLER_H

// взаимодействие между пользовательским интерфейсом и WeatherManager

#include <QObject>
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValueRef>
#include <QDebug>
#include <QDate>
#include <QDateTime>

class ClientController : public QObject
{
    Q_OBJECT
public:
    explicit ClientController(QObject *parent = nullptr);
    Q_INVOKABLE void getDataSearchCity(const QString &data);

public slots:
    void slotWeatherData(const QJsonObject &jsonObj);
    Q_INVOKABLE QString getDescription();
    Q_INVOKABLE QString getTemp();
    Q_INVOKABLE QString getFeelsLike();
    Q_INVOKABLE QString getTempMax();
    Q_INVOKABLE QString getTempMin();
    Q_INVOKABLE QString getWindSpeed();
    Q_INVOKABLE QString getHumidity();
    Q_INVOKABLE QString getPressure();

private:
    struct WeatherData{
        QString city;
        QDate date;
        QString description;
        double temp;
        double feels_like;
        double temp_max;
        double temp_min;
        double wind_speed;
        int humidity;
        int pressure;
    };
    WeatherData weatherData;
    void setData(const QJsonObject &jsonObj);
    void setData(const QString &city, const QDate &date);
signals:
    void cityChange(const QString &city);
    void dataUpdated();
};

#endif // CLIENTCONTROLLER_H
