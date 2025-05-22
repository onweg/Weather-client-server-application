#ifndef ICONFIGPROVIDER_H
#define ICONFIGPROVIDER_H

#include <string>

#include "../../entities/ApiConfig.h"
#include "../../entities/ServerHostConfig.h"
#include "../../utils/Result.h"

class IConfigProvider
{
  public:
	virtual ~IConfigProvider() = default;
	virtual Result<ApiConfig> getApiConfig() = 0;
	virtual Result<ServerHostConfig> getServerHostConfig() = 0;
};

#endif // ICONFIGPROVIDER_H
