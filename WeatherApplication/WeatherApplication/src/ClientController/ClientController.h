#ifndef CLIENTCONTROLLER_H
#define CLIENTCONTROLLER_H

// взаимодействие между пользовательским интерфейсом и WeatherManager

#include <QObject>
#include <QString>
#include <QDebug>
#include <QDate>
#include <QDateTime>
#include <QThread>
#include <QVariantMap>
#include <QVariant>
#include <QScopedPointer>
#include "WeatherUpdater.h"
#include "../Models/WeekWeatherData.h"
#include "../Models/WeatherData.h"
#include "../Models/AuthorizationReply.h"
#include "../Models/ApiReply.h"

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
    WeatherData weatherData_;
    WeekWeatherData weekWeatherData_;
    void setNextDay();
    void setPrevDay();

    QScopedPointer<QThread> updaterThread_;
    WeatherUpdater *updater_;

public slots:
    void slotWeatherDataArrived(const WeatherData &data);
    void slotWeekWeatherDataArrived(const WeekWeatherData &data);
    void slotRecivedAuthorizationData(const AuthorizationReply &data);

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
