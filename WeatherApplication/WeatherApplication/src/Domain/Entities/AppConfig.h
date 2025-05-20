#ifndef APPCONFIG_H
#define APPCONFIG_H

#include "ApiConfig.h"
#include "ServerHostConfig.h"

class AppConfig
{
public:
    AppConfig();
    AppConfig(const ServerHostConfig& serverHostConfig, const ApiConfig& apiConfig);

    const ServerHostConfig& getServerHostConfig() const;
    void setServerHostConfig(const ServerHostConfig& config);

    const ApiConfig& getApiConfig() const;
    void setApiConfig(const ApiConfig& config);

private:
    ServerHostConfig m_serverHostConfig;
    ApiConfig m_apiConfig;
};

#endif // APPCONFIG_H
