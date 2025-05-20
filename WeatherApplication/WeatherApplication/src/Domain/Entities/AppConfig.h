#ifndef APPCONFIG_H
#define APPCONFIG_H

#include "ApiConfig.h"
#include "ServerHostConfig.h"

class AppConfig
{
private:
    ServerHostConfig m_serverHostConfig;
    ApiConfig m_apiConfig;

public:
    AppConfig();

    const ServerHostConfig& getServerHostConfig() const;
    void setServerHostConfig(const ServerHostConfig& config);

    const ApiConfig& getApiConfig() const;
    void setApiConfig(const ApiConfig& config);
};

#endif // APPCONFIG_H
