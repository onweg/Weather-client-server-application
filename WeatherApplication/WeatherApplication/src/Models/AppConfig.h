#ifndef APPCONFIG_H
#define APPCONFIG_H

#include "../Models/ApiConfig.h"
#include "../Models/ServerHostConfig.h"

struct AppConfig
{
    ServerHostConfig serverHostConfig;
    ApiConfig apiConfig;
};

#endif // APPCONFIG_H