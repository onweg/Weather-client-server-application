#include "AppConfigJsonConverter.h"

AppConfigJsonConverter::AppConfigJsonConverter() {}

bool AppConfigJsonConverter::fromJson(const QJsonObject &jsonObject,
                                      AppConfigDto &config)
{
	if (!parseServerHostConfig(jsonObject, config.serverHostConfig))
	{
		return false;
	}
	if (!parseApiConfig(jsonObject, config.apiConfig))
	{
		return false;
	}
	return true;
}

bool AppConfigJsonConverter::parseServerHostConfig(
    const QJsonObject &jsonObject, ServerHostConfigDto &config)
{
	const QJsonObject hostObj = getJsonObject(jsonObject, "server host");
	if (hostObj.isEmpty())
		return false;
	config.ip = getStringValue(hostObj, "ip");
	config.port = getStringValue(hostObj, "port");
	return !config.ip.empty() && !config.port.empty();
}

bool AppConfigJsonConverter::parseApiConfig(const QJsonObject &jsonObject,
                                            ApiConfigDto &config)
{
	const QJsonObject apiObj = getJsonObject(jsonObject, "api");
	if (apiObj.isEmpty())
		return false;
	config.urlFindCityByName = getStringValue(apiObj, "urlFindCityByName");
	config.urlFindWeatherByCoordinates =
	    getStringValue(apiObj, "urlFindWeatherByCoordinates");
	config.key = getStringValue(apiObj, "key");
	return !config.urlFindCityByName.empty() &&
	       !config.urlFindWeatherByCoordinates.empty() && !config.key.empty();
}

QJsonObject AppConfigJsonConverter::getJsonObject(const QJsonObject &obj,
                                                  const QString &key)
{
	if (obj.contains(key) && obj[key].isObject())
	{
		return obj[key].toObject();
	}
	return QJsonObject();
}

std::string AppConfigJsonConverter::getStringValue(const QJsonObject &obj,
                                                   const QString &key)
{
	if (obj.contains(key) && obj[key].isString())
	{
		return obj[key].toString().toStdString();
	}
	return {};
}
