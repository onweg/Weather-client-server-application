#include "AppConfig.h"

AppConfig::AppConfig() : m_serverHostConfig(), m_apiConfig() {}

AppConfig::AppConfig(const ServerHostConfig &serverHostConfig,
                     const ApiConfig &apiConfig)
 : m_serverHostConfig(serverHostConfig), m_apiConfig(apiConfig)
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
