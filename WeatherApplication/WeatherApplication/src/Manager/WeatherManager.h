#ifndef WEATHERMANAGER_H
#define WEATHERMANAGER_H

#include <QObject>
#include <QDate>
#include <QJsonObject>
#include <QDebug>
#include <QDateTime>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QThread>
#include <QScopedPointer>
#include "WeatherApiClient.h"
#include "WeatherCache.h"
#include "CacheCleaner.h"
#include <QFile>
#include <QCoreApplication>
#include "../Utils/WeatherJsonConverter.h"
#include "../Models/WeekWeatherData.h"
#include "../Models/WeatherData.h"
#include "../Models/AuthorizationReply.h"
#include "../Models/ApiReply.h"
#include "../Models/ServerHost.h"

class WeatherManager : public QObject
{
    Q_OBJECT
public:
    explicit WeatherManager(QObject *parent = nullptr);
    ~WeatherManager();
private:
    QString user_;
    QString desiredCity_;
    QDate desiredDate_;
    ServerHost serverHost_;

    WeatherApiClient *api_;
    WeatherCache cache_;
    QNetworkAccessManager *networkManager_;

    QScopedPointer<QThread> cleanerThread_;
    CacheCleaner *cacheCleaner_;


public slots:
    void slotFindWeatherData(const QString &city, const QDate &date);
    void slotRecivedWeatherDataFromAPI(const ApiReply &jsonObj);
    void sloRecivedAuthorizationData(const QString &command, const QString &login, const QString &password);
    void slotFindWeekWeatherData();

    bool loadConfig();

private slots:
    void onReplyFinished(QNetworkReply *reply);


signals:
    void sendWeatherDataToController(const WeatherData &data);
    void sendWeekWeatherDataToController(const WeekWeatherData &data);
    void submitCompletedWeatherDataSearchRequest(const QString &user, const QString &city, const QDate &date);

    void sendAuthorizationResult(const AuthorizationReply &data);


};

#endif // WEATHERMANAGER_H
