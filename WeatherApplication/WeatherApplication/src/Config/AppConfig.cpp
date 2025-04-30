#include "AppConfig.h"

bool AppConfig::fromJson(const QJsonObject &obj, AppConfig &config)
{
    if (!parseServerHostConfig(obj, config.serverHostConfig)) {
        return false;
    }
    if (!parseApiConfig(obj, config.rawApiConfig)) {
        return false;
    }
    return true;
}

bool AppConfig::parseServerHostConfig(const QJsonObject &obj, ServerHostConfig &config)
{
    if (!obj.contains("server host") || !obj["server host"].isObject()) {
        return false;
    }
    QJsonObject serverHostObj = obj["server host"].toObject();
    if (!serverHostObj.contains("ip") || !serverHostObj.contains("port")) {
        return false;
    }
    config.ip = serverHostObj["ip"].toString();
    config.port = serverHostObj["port"].toString();
    return true;
}

bool AppConfig::parseApiConfig(const QJsonObject &obj, ApiConfig &config)
{
    if (!obj.contains("api") || !obj["api"].isObject()) {
        return false;
    }
    QJsonObject apiObj = obj["api"].toObject();
    if (!apiObj.contains("urlFindCityByName") || !apiObj.contains("urlFindWeatherByCoordinates") || !apiObj.contains("key")) {
        return false;
    }
    config.urlFindCityByName = apiObj["urlFindCityByName"].toString();
    config.urlFindWeatherByCoordinates = apiObj["urlFindWeatherByCoordinates"].toString();
    config.key = apiObj["key"].toString();
    return true;
}
