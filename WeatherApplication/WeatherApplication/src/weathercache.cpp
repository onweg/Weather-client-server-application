#include "weathercache.h"

WeatherCache::WeatherCache(QObject *parent) : QObject(parent)
{

}

bool WeatherCache::hasValidData(const QString &city)
{
    if (!cache.contains(city)) {
        return false;
    }
    return cache[city].timestamp.secsTo(QDateTime::currentDateTime()) < CACHE_EXPIRATION_TIME;
}

QJsonObject WeatherCache::getData(const QString &city, const QDate &date)
{

}

void WeatherCache::addData(const QString &city, const QJsonObject &jsonObj)
{
    if (hasValidData(city)) {
        return;
    }
    removeData(city);
    QJsonObject data;

//    WeatherData weatherData = WeatherData();
//    if (jsonObj.contains("error")) {
//        weatherData.city = jsonObj["error"].toString();
//        weatherData.description = "...";
//        return ;
//    }
//    if (jsonObj.contains("city") && jsonObj["city"].isObject()) {
//        QJsonObject cityObject = jsonObj["city"].toObject();
//        weatherData.city = cityObject["name"].toString();
//    }
//    if (jsonObj.contains("list") && jsonObj["list"].isArray()) {
//        QJsonArray listArray = jsonObj["list"].toArray();
//        if (!listArray.isEmpty()) {
//            QJsonObject firstDay = listArray[0].toObject();
//            if (firstDay.contains("dt")) {
//                qint64 timestamp = firstDay["dt"].toInt();
//                QDateTime dateTime;
//                dateTime.setTime_t(static_cast<uint>(timestamp));
//                weatherData.date = dateTime.date();
//            }
//            if (firstDay.contains("main") && firstDay["main"].isObject()) {
//                QJsonObject mainObject = firstDay["main"].toObject();
//                weatherData.temp = mainObject["temp"].toDouble();
//                weatherData.feels_like = mainObject["feels_like"].toDouble();
//                weatherData.temp_max = mainObject["temp_max"].toDouble();
//                weatherData.temp_min = mainObject["temp_min"].toDouble();
//                weatherData.humidity = mainObject["humidity"].toInt();
//                weatherData.pressure = mainObject["pressure"].toInt();
//            }
//            if (firstDay.contains("weather") && firstDay["weather"].isArray()) {
//                QJsonArray weatherArray = firstDay["weather"].toArray();
//                if (!weatherArray.isEmpty()) {
//                    QJsonObject weatherObject = weatherArray[0].toObject();
//                    weatherData.description = weatherObject["description"].toString();
//                }
//            }
//            if (firstDay.contains("wind") && firstDay["wind"].isObject()) {
//                QJsonObject windObject = firstDay["wind"].toObject();
//                weatherData.wind_speed = windObject["speed"].toDouble(); // Скорость ветра
//            }
//        }
//    }

    emit dataInCacheUpdtaed();
}

void WeatherCache::removeData(const QString &city)
{
    // если такого города не нашллось, то ничего удалятьи не надо
}

void WeatherCache::slotFindWeatherDataInCache(const QString &city, const QDate &date)
{
    // найти данные о погоде в определенном городе в определенную дату
}
