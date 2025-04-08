#include "weathermanager.h"

WeatherManager::WeatherManager(QObject *parent) : QObject(parent)
{

}

void WeatherManager::slotCityChange(const QString &city)
{
    // перед тем как отправлять надо проверять в ке
    emit findCityData(city);
}

void WeatherManager::slotRecivedWeatherData(const QJsonObject &jsonObj)
{


    // занести в кеш
    // занести в бд
    // отправить контроллеру
    emit weatherData(jsonObj);

}
