#ifndef APPCONFIG_H
#define APPCONFIG_H

#include "ApiConfig.h"
#include "ServerHostConfig.h"

struct AppConfig
{
    ServerHostConfig serverHostConfig;
    ApiConfig apiConfig;
};

#endif // APPCONFIG_H
