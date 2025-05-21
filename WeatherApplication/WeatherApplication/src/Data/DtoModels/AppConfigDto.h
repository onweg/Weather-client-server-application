#ifndef APPCONFIGDTO_H
#define APPCONFIGDTO_H

#include "ApiConfigDto.h"
#include "ServerHostConfigDto.h"

struct AppConfigDto
{
public:
    ServerHostConfigDto serverHostConfig;
    ApiConfigDto apiConfig;
};

#endif // APPCONFIGDTO_H
