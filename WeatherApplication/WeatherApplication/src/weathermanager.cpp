#include "weathermanager.h"

WeatherManager::WeatherManager(QObject *parent) : QObject(parent)
{

}

void WeatherManager::slotFindCity(const QString &city)
{
    emit findCity(city);
}

void WeatherManager::slotRecivedWeatherData(const QJsonObject &jsonObj)
{


    // занести в кеш
    // занести в бд
    // отправить контроллеру
    emit weatherData(jsonObj);

}
