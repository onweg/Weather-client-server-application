//#include "WeatherCache.h"

//WeatherCache::WeatherCache(QObject *parent) : QObject(parent)
//{

//}

//WeatherCache::CacheStatus WeatherCache::hasValidData(const QString &city, const QDate &date)
//{
//    if (!cache_.contains(city)) {
//        return CityNotFound;
//    }
//    if  (cache_[city].timestamp.secsTo(QDateTime::currentDateTime()) > CACHE_EXPIRATION_TIME ) {
//         removeData(city);
//         return Expired;
//    }
//    int index = getIndexInListByDate(date);
//    if (index < 0 || index >= cache_[city].data.dailyWeather.size()) {
//        return DateNotFound;
//    }
//    return Valid;
//}

//WeatherData WeatherCache::getWeatherData(const QString &city, const QDate &date)
//{
//    if (hasValidData(city, date) == Valid) {
//        int index = getIndexInListByDate(date);
//        return cache_[city].data.dailyWeather[index];
//    }
//    WeatherData error;
//    error.messageError = "Not Found Weather";
//    return error;
//}

//WeekWeatherData WeatherCache::getWeekWeatherData(const QString &city)
//{
//    if (hasValidData(city) == Valid) {
//        return cache_[city].data;
//    }
//    WeekWeatherData error;
//    error.messageError = "Not Found Weather";
//    return error;
//}

//void WeatherCache::addData(const QString &city, const WeekWeatherData &data)
//{
//    cache_[city] = {data, QDateTime::currentDateTime()};
//}

//void WeatherCache::removeData(const QString &city)
//{
//    cache_.remove(city);
//}

//void WeatherCache::clearExpired()
//{
//    auto it = cache_.begin();
//    while (it != cache_.end()) {
//        if (it->timestamp.secsTo(QDateTime::currentDateTime()) > CACHE_EXPIRATION_TIME) {
//            it = cache_.erase(it);
//        } else {
//            ++it;
//        }
//    }
//}

//int WeatherCache::getIndexInListByDate(const QDate &date)
//{
//    QDate currDate = QDate::currentDate();
//    int index = currDate.daysTo(date);
//    return index;
//}
