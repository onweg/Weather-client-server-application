#ifndef WEATHERMANAGER_H
#define WEATHERMANAGER_H

#include <QObject>
#include <QDate>
#include <QJsonObject>
#include <QDebug>
#include <QDateTime>

class WeatherManager : public QObject
{
    Q_OBJECT
public:
    explicit WeatherManager(QObject *parent = nullptr);

private:
    QString desiredCity;
    QDate desiredDate;

public slots:
    void slotFindWeatherData(const QString &city, const QDate &date);
    void slotRecivedWeatherDataFromCache(const QJsonObject &jsonObj);
    void slotRecivedWeatherDataFromAPI(const QJsonObject &jsonObj);
    void slotDataInCacheUpdated();

private slots:

signals:
    void findWeatherDataInCache(const QString &city, const QDate &date);
    void sendWeatherDataToController(const QJsonObject &jsonObj);
    void submitCompletedWeatherDataSearchRequest(const QString &user, const QDateTime &timestamp, const QString &city, const QDate &date, const QJsonObject &jsonObj);
    void findWeatherDataInAPI(const QString &city);
    void addNewWeatherDataInCache(const QString &city, const QJsonObject &jsonObj);

};

#endif // WEATHERMANAGER_H
