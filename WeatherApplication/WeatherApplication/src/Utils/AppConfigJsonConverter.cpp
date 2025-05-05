#include "AppConfigJsonConverter.h"

AppConfigJsonConverter::AppConfigJsonConverter()
{
}

bool AppConfigJsonConverter::fromJson(const QJsonObject& jsonObject, AppConfig& config)
{
    if (!parseServerHostConfig(jsonObject, config.serverHostConfig)) {
        return false;
    }

    if (!parseApiConfig(jsonObject, config.apiConfig)) {
        return false;
    }

    return true;
}

bool AppConfigJsonConverter::parseServerHostConfig(const QJsonObject& jsonObject, ServerHostConfig& config)
{
    if (!jsonObject.contains("server host") || !jsonObject["server host"].isObject()) {
        return false;
    }
    QJsonObject serverHostObj = jsonObject["server host"].toObject();
    if (!serverHostObj.contains("ip") || !serverHostObj["ip"].isString()) {
        return false;
    }
    if (!serverHostObj.contains("port") || !serverHostObj["port"].isString()) {
        return false;
    }
    config.ip = serverHostObj["ip"].toString().toStdString();
    config.port = serverHostObj["port"].toString().toStdString();
    return true;
}

bool AppConfigJsonConverter::parseApiConfig(const QJsonObject& jsonObject, ApiConfig& config)
{
    if (!jsonObject.contains("api") || !jsonObject["api"].isObject()) {
        return false;
    }

    QJsonObject apiObj = jsonObject["api"].toObject();
    if (!apiObj.contains("urlFindCityByName") || !apiObj["urlFindCityByName"].isString()) {
        return false;
    }
    if (!apiObj.contains("urlFindWeatherByCoordinates") || !apiObj["urlFindWeatherByCoordinates"].isString()) {
        return false;
    }
    if (!apiObj.contains("key") || !apiObj["key"].isString()) {
        return false;
    }

    config.urlFindCityByName = apiObj["urlFindCityByName"].toString().toStdString();;
    config.urlFindWeatherByCoordinates = apiObj["urlFindWeatherByCoordinates"].toString().toStdString();;
    config.key = apiObj["key"].toString().toStdString();;
    return true;
}
