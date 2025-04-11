#include "weathermanager.h"

WeatherManager::WeatherManager(QObject *parent) : QObject(parent)
{

}

void WeatherManager::slotFindWeatherData(const QString &city, const QDate &date)
{
    // посмотреть данные у кеш
    desiredCity = city;
    desiredDate = date;
    emit findWeatherDataInCache(city, date);
}

void WeatherManager::slotRecivedWeatherDataFromCache(const QJsonObject &jsonObj)
{
    // если в json файле есть желаемый город
        // emit sendWeatherDataToController(jsonObj);
        // emit submitCompletedWeatherDataSearchRequest("local user", QDateTime::currentTime, desiredCity, desiredDate, jsonObj);
    // если в json файле нет желаемого города
        // emit findWeatherDataFromAPI(desiredCity);

}

void WeatherManager::slotRecivedWeatherDataFromAPI(const QJsonObject &jsonObj)
{
    // emit addNewWeatherDataInCache(desiredCity, jsonObj);
}

void WeatherManager::slotDataInCacheUpdated()
{
    // emit findWeatherDataInCache(desiredCity, desiredDate);
}
