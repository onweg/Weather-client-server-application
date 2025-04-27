#include "weathercache.h"

WeatherCache::WeatherCache(QObject *parent) : QObject(parent)
{

}

WeatherCache::CacheStatus WeatherCache::hasValidData(const QString &city, const QDate &date)
{
    if (!cache.contains(city)) {
        return CityNotFound;
    }
    if  (cache[city].timestamp.secsTo(QDateTime::currentDateTime()) > CACHE_EXPIRATION_TIME ) {
         removeData(city);
         return Expired;
    }
    int index = getgetIndexInListByDateIndexByDate(date);
    if (index < 0 || index >= cache[city].data.dailyWeather.size()) {
        return DateNotFound;
    }
    return Valid;
}

WeatherData WeatherCache::getWeatherData(const QString &city, const QDate &date)
{
    if (hasValidData(city, date) == Valid) {
        int index = getIndexInListByDate(date);
        return cache[city].data.dailyWeather[index];
    }
    // result["city"] = cache[city].data["city"].toString();
    // result["date"] = date.toString("yyyy-MM-dd");
    // qDebug() << city << " " << date.toString("yyyy-MM-dd");
    // QJsonDocument doc(result);
    // qDebug() << "getCache: " << doc.toJson(QJsonDocument::Indented);
    WeatherData error;
    error.messageError = "Not Found Weather";
    return result;
}

WeatherData getWeekWeatherData(const QString &city) {
    if (hasValidData(city) == Valid) {
        return cache[city].data.dailyWeather;
    }
    WeekWeatherData error;
    error.messageError = "Not Found Weather";
    return result;
}

int getIndexInListByDate(const QDate &date) {
    QDate currDate = QDate:currentDate();
    int index = currDate.daysTo(date);
    return index;
}

void WeatherCache::addData(const QString &city, const WeekWeatherData &data) {
    cache[city] = {data, QDateTime::currentDateTime()};
}

void WeatherCache::removeData(const QString &city)
{
    cache.remove(city);
}

void WeatherCache::clearExpired()
{
    auto it = cache.begin();
    while (it != cache.end()) {
        if (it->timestamp.secsTo(QDateTime::currentDateTime()) > CACHE_EXPIRATION_TIME) {
            it = cache.erase(it);
        } else {
            ++it;
        }
    }
}
