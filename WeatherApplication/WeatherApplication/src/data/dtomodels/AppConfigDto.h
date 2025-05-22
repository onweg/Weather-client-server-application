#ifndef APPCONFIGDTO_H
#define APPCONFIGDTO_H

#include "ApiConfigDto.h"
#include "ServerHostConfigDto.h"
#include "CacheConfigDto.h"

struct AppConfigDto
{
	ServerHostConfigDto serverHostConfig;
	ApiConfigDto apiConfig;
    CacheConfigDto cacheConfig;
};

#endif // APPCONFIGDTO_H
