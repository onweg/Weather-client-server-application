#include "ConfigProvider.h"

#include <QDebug>

ConfigProvider::ConfigProvider(std::shared_ptr<IConfigLoader> configLoader)
 : configLoader_(std::move(configLoader))
{
}

ApiConfig ConfigProvider::getApiConfig()
{
	initConfig();
	return appConfig_->getApiConfig();
}

ServerHostConfig ConfigProvider::getServerHostConfig()
{
	initConfig();
	return appConfig_->getServerHostConfig();
}

CacheConfig ConfigProvider::getCacheConfig()
{
	initConfig();
	return appConfig_->getCacheConfig();
}

void ConfigProvider::initConfig()
{
	if (!appConfig_)
	{
		auto result = configLoader_->load();
		if (!result.isSuccess())
		{
			throw std::runtime_error(result.errorMessage());
		}
		auto tmp = result.value();
		appConfig_ = std::make_shared<AppConfig>(tmp.getServerHostConfig(),
		                                         tmp.getApiConfig(),
		                                         tmp.getCacheConfig());
	}
}
