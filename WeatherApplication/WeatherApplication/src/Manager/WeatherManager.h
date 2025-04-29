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
#include <QFile>
#include <QCoreApplication>
#include "WeatherApiClient.h"
#include "WeatherCache.h"
#include "CacheCleaner.h"
#include "../Utils/WeatherJsonConverter.h"
#include "../Types/WeekWeatherData.h"
#include "../Types/WeatherData.h"
#include "../Types/AuthorizationReply.h"
#include "../Types/ApiReply.h"
#include "../Types/ApiConfig.h"
#include "../Types/ServerHostConfig.h"
#include "../Config/AppConfig.h"


class WeatherManager : public QObject
{
    Q_OBJECT
public:
    explicit WeatherManager(QObject *parent = nullptr);
    ~WeatherManager();
    bool loadConfig();

private:
    QString user_;
    QString desiredCity_;
    QDate desiredDate_;
    ServerHostConfig serverHostConfig_;

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

private slots:
    void onReplyFinished(QNetworkReply *reply);

signals:
    void sendWeatherDataToController(const WeatherData &data);
    void sendWeekWeatherDataToController(const WeekWeatherData &data);
    void submitCompletedWeatherDataSearchRequest(const QString &user, const QString &city, const QDate &date);
    void sendAuthorizationResult(const AuthorizationReply &data);

};

#endif // WEATHERMANAGER_H
