#ifndef ICONFIGPROVIDER_H
#define ICONFIGPROVIDER_H

#include <string>

#include "../../../infrastructure/config/ApiConfig.h"
#include "../../../infrastructure/config/CacheConfig.h"
#include "../../../infrastructure/config/ServerHostConfig.h"

class IConfigProvider
{
  public:
	virtual ~IConfigProvider() = default;
	virtual ApiConfig getApiConfig() = 0;
	virtual ServerHostConfig getServerHostConfig() = 0;
	virtual CacheConfig getCacheConfig() = 0;
};

#endif // ICONFIGPROVIDER_H
