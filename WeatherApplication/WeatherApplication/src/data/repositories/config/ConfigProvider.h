#ifndef CONFIGPROVIDER_H
#define CONFIGPROVIDER_H

#include <memory>

#include "../../../domain/interfaces/config/IConfigLoader.h"
#include "../../../domain/interfaces/config/IConfigProvider.h"

class ConfigProvider : public IConfigProvider
{
  public:
	explicit ConfigProvider(std::shared_ptr<IConfigLoader> configLoader);
	ApiConfig getApiConfig() override;
	ServerHostConfig getServerHostConfig() override;
	CacheConfig getCacheConfig() override;

  private:
	void initConfig();

	std::shared_ptr<IConfigLoader> configLoader_;
	std::shared_ptr<AppConfig> appConfig_;
};

#endif // CONFIGPROVIDER_H
