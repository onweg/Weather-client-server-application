#ifndef CONFIGPROVIDER_H
#define CONFIGPROVIDER_H

#include <memory>

#include "../../../domain/interfaces/config/IConfigLoader.h"
#include "../../../domain/interfaces/config/IConfigProvider.h"

class ConfigProvider : public IConfigProvider
{
  public:
	explicit ConfigProvider(std::shared_ptr<IConfigLoader> configLoader);
	Result<ApiConfig> getApiConfig() override;
	Result<ServerHostConfig> getServerHostConfig() override;
    Result<CacheConfig> getCacheConfig() override;

  private:
	std::shared_ptr<IConfigLoader> configLoader_;
	Result<AppConfig> appConfig_;
};

#endif // CONFIGPROVIDER_H
