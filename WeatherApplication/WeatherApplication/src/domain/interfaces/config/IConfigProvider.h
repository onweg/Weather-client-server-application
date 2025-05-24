#ifndef ICONFIGPROVIDER_H
#define ICONFIGPROVIDER_H

#include <string>

#include "../../../infrastructure/config/ApiConfig.h"
#include "../../../infrastructure/config/CacheConfig.h"
#include "../../../infrastructure/config/ServerHostConfig.h"
#include "../../utils/Result.h"

class IConfigProvider
{
  public:
	virtual ~IConfigProvider() = default;
	virtual Result<ApiConfig> getApiConfig() = 0;
	virtual Result<ServerHostConfig> getServerHostConfig() = 0;
	virtual Result<CacheConfig> getCacheConfig() = 0;
};

#endif // ICONFIGPROVIDER_H
