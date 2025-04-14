#include "weathermanager.h"

WeatherManager::WeatherManager(QObject *parent) : QObject(parent)
{

    QObject::connect(&api, &WeatherApiClient::sendRecivedWeatherDataFromAPI, this, &WeatherManager::slotRecivedWeatherDataFromAPI); // возвращаем сформированный json по поиску данных о погоде в города


    // QObject::connect(this, &WeatherManager::findWeatherDataInCache, &cache, &WeatherCache::slotFindWeatherDataInCache); // ( сначала смотрим в кеш данные о горожде в определенный день)
    // QObject::connect(&cache, &WeatherCache::sendWeatherDataFromCache, this, &WeatherManager::slotRecivedWeatherDataFromCache); // ( взвращает в манагер сформированный json )
    // QObject::connect(this, &WeatherManager::findWeatherDataInAPI, &api, &WeatherApiClient::slotFindWeatherDataInAPI);     // если нет данных то идем искать все данные о городе через апи
    // QObject::connect(this, &WeatherManager::addNewWeatherDataInCache, &cache, &WeatherCache::slotAddNewWeatherDataInCache); // должен сохранить новые данные из api что получили )
    // QObject::connect(&cache, &WeatherCache::dataInCacheUpdtaed, this, &WeatherManager::slotDataInCacheUpdated); // обновили данные в кеш
}

void WeatherManager::slotFindWeatherData(const QString &city, const QDate &date)
{
    desiredCity = city;
    desiredDate = date;
    int status = cache.hasValidData(desiredCity, desiredDate);
    if (status == 0) {
        emit sendWeatherDataToController(cache.getData(desiredCity, desiredDate));
    } else if (status == 1){
        api.findWeatherDataInAPI(desiredCity);
    }

}

void WeatherManager::slotRecivedWeatherDataFromAPI(const QJsonObject &jsonObj)
{
    QJsonObject correctJsonData = dataEditor.getCorrectData(jsonObj);
    QJsonDocument doc2(correctJsonData);
    qDebug().noquote() << doc2.toJson(QJsonDocument::Indented);
    if (correctJsonData.isEmpty()) {
        QJsonObject error;
        error["error"] = "Город не найден!";
        emit sendWeatherDataToController(error);

    } else {
        cache.addData(desiredCity, correctJsonData);
        QJsonObject tmp = cache.getData(desiredCity, desiredDate);
        tmp["city"] = correctJsonData["city"].toString();
        tmp["date"] = desiredDate.toString("yyyy-MM-dd");
        QJsonDocument doc(tmp);
        qDebug().noquote() << doc.toJson(QJsonDocument::Indented);
        emit sendWeatherDataToController(tmp);
    }
    // отправить бд что был (не)удачный запрос
}

