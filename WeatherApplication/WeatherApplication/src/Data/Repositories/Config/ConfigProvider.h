#ifndef CONFIGPROVIDER_H
#define CONFIGPROVIDER_H

#include <memory>

#include "../../../Domain/Interfaces/Config/IConfigProvider.h"
#include "../../../Domain/Interfaces/Config/IConfigLoader.h"

class ConfigProvider : public IConfigProvider {
public:
    explicit ConfigProvider(std::shared_ptr<IConfigLoader> configLoader);
    // принимаем ничего возвращаем entiry
    Result<ApiConfig> getApiConfig() override;
    Result<ServerHostConfig> getServerHostConfig() override;
private:
    std::shared_ptr<IConfigLoader> configLoader_;
    Result<AppConfig> appConfig_;
};

#endif // CONFIGPROVIDER_H

