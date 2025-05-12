#ifndef ICONFIGPROVIDER_H
#define ICONFIGPROVIDER_H

#include "../../Entities/ApiConfig.h"
#include "../../Entities/ServerHostConfig.h"
#include "../../Utils/Result.h"
#include <string>

class IConfigProvider {
public:
 virtual ~IConfigProvider() = default;
 virtual Result<ApiConfig> getApiConfig() = 0;
 virtual Result<ServerHostConfig> getServerHostConfig() = 0;
};

#endif	// ICONFIGPROVIDER_H
