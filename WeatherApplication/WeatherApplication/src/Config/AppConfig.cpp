#include "appconfig.h"
#include <QJsonObject>
#include <QJsonArray>

bool AppConfig::fromJson(const QJsonObject &obj, AppConfig &config)
{
    if (!obj.contains("server host")) return false;
    QJsonObject serverHostObj = obj["server host"].toObject();
    if (!serverHostObj.contains("ip") || !serverHostObj.contains("port")) return false;
    config.serverHostConfig.ip = serverHostObj["ip"].toString();
    config.serverHostConfig.port = serverHostObj["port"].toString();
    if (!obj.contains("api")) return false;
    QJsonObject apiObj = obj["api"].toObject();
    if (!apiObj.contains("urlFindCityByName") ||
        !apiObj.contains("urlFindWeatherByCoordinates") ||
        !apiObj.contains("key")) 
    {
        return false;
    }
    config.apiConfig.urlFindCityByName = apiObj["urlFindCityByName"].toString();
    config.apiConfig.urlFindWeatherByCoordinates = apiObj["urlFindWeatherByCoordinates"].toString();
    config.apiConfig.key = apiObj["key"].toString();
    return true;
}
