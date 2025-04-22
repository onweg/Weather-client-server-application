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
#include <QThread>
#include <QVariantMap>
#include <QScopedPointer>
#include "weatherupdater.h"

#define NUMBEROFDAYS 5

class ClientController : public QObject
{
    Q_OBJECT
public:
    explicit ClientController(QObject *parent = nullptr);
    ~ClientController();
    Q_INVOKABLE void clickSearchCityButton(const QString &data);
    Q_INVOKABLE void clickNextDayButton();
    Q_INVOKABLE void clickPrevDayButton();
    Q_INVOKABLE void clickWeekWeatherDataButton();
    Q_INVOKABLE void sendAuthorizationData(const QString &command, const QString &login, const QString &password);

    Q_INVOKABLE QVariantMap getWeatherDataFromOneDay();
    Q_INVOKABLE QVariantMap getWeatherDataFromWeek();

private:
    struct WeatherData{
        double lat;
        double lon;
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
    void setNextDay();
    void setPrevDay();

    QScopedPointer<QThread> updaterThread;
    WeatherUpdater *updater;

    QVariantMap convertToVariantMap(const WeatherData &data) const;
    QVariantMap weekWeatherData;



public slots:
    void slotWeatherDataArrived(const QJsonObject &jsonObj);
    void slotWeekWeatherDataArrived(const QJsonObject &jsonObj);
    void slotRecivedAuthorizationData(const QJsonObject &jsonObj);



private slots:
    void slotUpdateWeatherFromUpdater();

signals:
    void findWeatherData(const QString &city, const QDate &date = QDate::currentDate());
    void findWeekWeatherData();

    void dataUpdated();
    void weekDataUpdated();

    void sendAuthorizationDataToManager(const QString &command, const QString &login, const QString &password);
    void authorizationCompleted();
    void authorizationFailed(const QString &message);
};

#endif // CLIENTCONTROLLER_H
