#ifndef WEATHERMANAGER_H
#define WEATHERMANAGER_H

#include <QObject>
#include <QDate>
#include <QJsonObject>
#include <QDebug>
#include <QDateTime>
#include "weatherapiclient.h"
#include "weathercache.h"
#include "clientcontroller.h"
#include "../Utils/weatherjsonconverter.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QThread>
#include <QScopedPoiter>
#include "cachecleaner.h"

class WeatherManager : public QObject
{
    Q_OBJECT
public:
    explicit WeatherManager(QObject *parent = nullptr);
    ~WeatherManager();
private:
    QString user;

    QString desiredCity;
    QDate desiredDate;
    WeatherApiClient api;
    WeatherCache cache;
    QNetworkAccessManager *networkManager;

    QScopedPointer<QThread> cleanerThread;
    CacheCleaner *cacheCleaner;


public slots:
    void slotFindWeatherData(const QString &city, const QDate &date);
    void slotRecivedWeatherDataFromAPI(const QJsonObject &jsonObj);
    void sloRecivedAuthorizationData(const QString &command, const QString &login, const QString &password);
    void slotFindWeekWeatherData();

private slots:
    void onReplyFinished(QNetworkReply *reply);

signals:
    void sendWeatherDataToController(const QJsonObject &jsonObj);
    void sendWeekWeatherDataToController(const QJsonObject &jsonObj);
    void submitCompletedWeatherDataSearchRequest(const QString &user, const QString &city, const QDate &date);

    void sendAuthorizationResult(const QJsonObject &jsonObj);


};

#endif // WEATHERMANAGER_H
