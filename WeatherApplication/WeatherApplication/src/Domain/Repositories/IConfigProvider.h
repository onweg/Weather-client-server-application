#ifndef ICONFIGPROVIDER_H
#define ICONFIGPROVIDER_H

#include <string>
#include "../Models/ApiConfig.h"
#include "../Models/ServerHostConfig.h"
#include "../Utils/Result.h"

class IConfigProvider {
public:
    virtual ~IConfigProvider() = default;
    virtual Result<ApiConfig> getApiConfig() = 0;
    virtual Result<ServerHostConfig> getServerHostConfig() = 0;
};

#endif // ICONFIGPROVIDER_H
