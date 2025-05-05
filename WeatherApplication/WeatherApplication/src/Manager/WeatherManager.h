//#ifndef WEATHERMANAGER_H
//#define WEATHERMANAGER_H

//#include <QObject>
//#include <QDate>
//#include <QDebug>
//#include <QDateTime>
//#include <QNetworkAccessManager>
//#include <QNetworkReply>
//#include <QThread>
//#include <QScopedPointer>
//#include <QFile>
//#include <QCoreApplication>
//#include "WeatherApiClient.h"
//#include "WeatherCache.h"
//#include "CacheCleaner.h"
//#include "../Models/WeekWeatherData.h"
//#include "../Models/WeatherData.h"
//#include "../Models/AuthorizationReply.h"
//#include "../Models/ApiReply.h"
//#include "../Models/ApiConfig.h"
//#include "../Models/ServerHostConfig.h"
//#include "../Models/AppConfig.h"
//#include "../Models/WeatherHistoryItem.h"
//#include "../Models/AuthorizationInfo.h"
//#include "../Utils/WeatherJsonConverter.h"
//#include "../Utils/AuthorizationInfoJsonConverter.h"
//#include "../Utils/AuthorizationReplyJsonConverter.h"
//#include "../Utils/AppConfigJsonConverter.h"


//class WeatherManager : public QObject
//{
//    Q_OBJECT
//public:
//    explicit WeatherManager(QObject *parent = nullptr);
//    ~WeatherManager();
//    bool loadConfig();

//private:
//    QString user_;
//    QString desiredCity_;
//    QDate desiredDate_;
//    ServerHostConfig serverHostConfig_;

//    WeatherApiClient *api_;
//    WeatherCache cache_;
//    QNetworkAccessManager *networkManager_;

//    QScopedPointer<QThread> cleanerThread_;
//    CacheCleaner *cacheCleaner_;

//    void addDataToDatabase();

//public slots:
//    void slotFindWeatherData(const QString &city, const QDate &date);
//    void slotRecivedWeatherDataFromAPI(const ApiReply &jsonObj);
//    void sloRecivedAuthorizationData(const AuthorizationInfo &data);
//    void slotFindWeekWeatherData();

//private slots:
//    void onReplyFinished(QNetworkReply *reply);

//signals:
//    void sendWeatherDataToController(const WeatherData &data);
//    void sendWeekWeatherDataToController(const WeekWeatherData &data);
//    void submitCompletedWeatherDataSearchRequest(const WeatherHistoryItem &item);
//    void sendAuthorizationResult(const AuthorizationReply &data);

//};

//#endif // WEATHERMANAGER_H
