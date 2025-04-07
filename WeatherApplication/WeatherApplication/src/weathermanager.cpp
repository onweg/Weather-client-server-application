#include "weathermanager.h"

WeatherManager::WeatherManager(QObject *parent) : QObject(parent)
{

}

void WeatherManager::slotCountryChange(const QString &zipCode, const QString &countryCode)
{
    // перед тем как отправлять надо проверять в ке
    emit countryChange(zipCode, countryCode);
}

void WeatherManager::slotRecivedJsonData(const QJsonObject &jsonObj)
{


    // получил json данные
    // занести в кеш
    // отправить контроллеру
    emit sendJsonDataFromAPI(jsonObj);

}
