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
    if (!parseCacheConfig(jsonObject, config.cacheConfig))
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
    config.baseUrl_ = getStringValue(apiObj, "baseUrl");
	config.key = getStringValue(apiObj, "key");
    return !config.baseUrl_.empty() && !config.key.empty();
}

bool AppConfigJsonConverter::parseCacheConfig(const QJsonObject &jsonObject,
                                              CacheConfigDto &config)
{
    const QJsonObject cacheObj = getJsonObject(jsonObject, "cache");
    if (cacheObj.isEmpty())
        return false;
    config.maxMemoryBytes = getIntValue(cacheObj, "maxMemoryBytes");
    return config.maxMemoryBytes;
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

int AppConfigJsonConverter::getIntValue(const QJsonObject &obj,
                                                   const QString &key)
{
    if (obj.contains(key))
    {
        return obj[key].toInt();
    }
    return {};
}
