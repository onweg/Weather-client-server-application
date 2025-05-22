#ifndef CONFIGPROVIDER_H
#define CONFIGPROVIDER_H

#include <memory>

#include "../../../Domain/Interfaces/Config/IConfigLoader.h"
#include "../../../Domain/Interfaces/Config/IConfigProvider.h"

class ConfigProvider : public IConfigProvider
{
  public:
	explicit ConfigProvider(std::shared_ptr<IConfigLoader> configLoader);
	Result<ApiConfig> getApiConfig() override;
	Result<ServerHostConfig> getServerHostConfig() override;

  private:
	std::shared_ptr<IConfigLoader> configLoader_;
	Result<AppConfig> appConfig_;
};

#endif // CONFIGPROVIDER_H
