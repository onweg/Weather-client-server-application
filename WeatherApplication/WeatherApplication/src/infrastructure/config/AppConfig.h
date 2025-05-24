#ifndef APPCONFIG_H
#define APPCONFIG_H

#include "ApiConfig.h"
#include "ServerHostConfig.h"
#include "CacheConfig.h"

class AppConfig
{
  public:
	AppConfig();
	AppConfig(const ServerHostConfig &serverHostConfig,
              const ApiConfig &apiConfig,
              const CacheConfig &cacheConfig);

	const ServerHostConfig &getServerHostConfig() const;
	void setServerHostConfig(const ServerHostConfig &config);

	const ApiConfig &getApiConfig() const;
	void setApiConfig(const ApiConfig &config);

    const CacheConfig &getCacheConfig() const;
    void setCacheConfig(const CacheConfig &config);

  private:
	ServerHostConfig m_serverHostConfig;
	ApiConfig m_apiConfig;
    CacheConfig m_cacheConfig;
};

#endif // APPCONFIG_H
