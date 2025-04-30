#ifndef WEATHERCACHE_H
#define WEATHERCACHE_H

#include <QObject>
#include <QDate>
#include <QDateTime>
#include <QMap>
#include <QString>
#include <QDebug>

#include "../Models/WeatherData.h"
#include "../Models/WeekWeatherData.h"

class WeatherCache : public QObject
{
    Q_OBJECT
public:
    explicit WeatherCache(QObject *parent = nullptr);

    enum CacheStatus {
        Valid,
        CityNotFound,
        DateNotFound,
        Expired
    };
    Q_ENUM(CacheStatus)

    static const int CACHE_EXPIRATION_TIME = 3600;
    CacheStatus hasValidData(const QString &city, const QDate &date = QDate::currentDate()); // 0 - успех 1 - нет города 2 - есть город, но нет даты 3 - данные устарели
    WeatherData getWeatherData(const QString &city, const QDate &date = QDate::currentDate());
    WeekWeatherData getWeekWeatherData(const QString &city);
    void addData(const QString &city, const WeekWeatherData &data);
    void removeData(const QString &city);
    void clearExpired();

private:
    int getIndexInListByDate(const QDate &date);
    struct CacheEntry{
        WeekWeatherData data;
        QDateTime timestamp;
    };
    QMap<QString, CacheEntry> cache_;
};

#endif // WEATHERCACHE_H
