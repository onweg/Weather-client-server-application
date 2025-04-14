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
    if (!cache[city].data.contains(date.toString("yyyy-MM-dd"))) {
        return DateNotFound;
    }
    return Valid;
}

QJsonObject WeatherCache::getData(const QString &city, const QDate &date)
{
    QJsonObject result = {};
    if (hasValidData(city, date) == Valid) {
        result = cache[city].data[date.toString("yyyy-MM-dd")].toObject();
    }
    result["city"] = cache[city].data["city"].toString();
    result["date"] = date.toString("yyyy-MM-dd");
    // qDebug() << city << " " << date.toString("yyyy-MM-dd");
    QJsonDocument doc(result);
    qDebug() << "getCache: " << doc.toJson(QJsonDocument::Indented);
    return result;
}

void WeatherCache::addData(const QString &city, const QJsonObject &data) {
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
