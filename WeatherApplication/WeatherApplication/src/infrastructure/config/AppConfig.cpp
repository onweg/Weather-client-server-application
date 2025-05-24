#include "AppConfig.h"

AppConfig::AppConfig() : m_serverHostConfig(), m_apiConfig(), m_cacheConfig() {}

AppConfig::AppConfig(const ServerHostConfig &serverHostConfig,
                     const ApiConfig &apiConfig, const CacheConfig &cacheConfig)
 : m_serverHostConfig(serverHostConfig), m_apiConfig(apiConfig),
   m_cacheConfig(cacheConfig)

{
}

const ServerHostConfig &AppConfig::getServerHostConfig() const
{
	return m_serverHostConfig;
}

void AppConfig::setServerHostConfig(const ServerHostConfig &config)
{
	m_serverHostConfig = config;
}

const ApiConfig &AppConfig::getApiConfig() const
{
	return m_apiConfig;
}

void AppConfig::setApiConfig(const ApiConfig &config)
{
	m_apiConfig = config;
}

const CacheConfig &AppConfig::getCacheConfig() const
{
	return m_cacheConfig;
}

void AppConfig::setCacheConfig(const CacheConfig &config)
{
	m_cacheConfig = config;
}
