#ifndef CLIENTCONTROLLER_H
#define CLIENTCONTROLLER_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QDate>
#include <QDateTime>
#include <QThread>
#include <QScopedPointer>
#include "WeatherUpdater.h"
#include "../Models/WeekWeatherModel.h"
#include "../Models/WeatherModel.h"
#include "../Types/AuthorizationReply.h"
#include "../Types/ApiReply.h"
#include "../Types/WeatherData.h"
#include "../Types/WeekWeatherData.h"
#include "../Types/AuthorizationInfo.h"

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

    Q_PROPERTY(WeatherModel* weatherModel READ getWeatherModel NOTIFY weatherDataUpdated)
    Q_PROPERTY(WeekWeatherModel* weekWeatherModel READ getWeekWeatherModel NOTIFY weekWeatherDataUpdated)

private:
    WeatherData weatherData_;
    WeekWeatherData weekWeatherData_;
    WeatherModel *weatherModel_ = nullptr;
    WeekWeatherModel *weekWeatherModel_ = nullptr;
    WeatherModel* getWeatherModel();
    WeekWeatherModel* getWeekWeatherModel();
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

    void weatherDataUpdated();
    void weekWeatherDataUpdated();

    void sendAuthorizationDataToManager(const AuthorizationInfo &data);
    void authorizationCompleted();
    void authorizationFailed(const QString &message);
};

#endif // CLIENTCONTROLLER_H
