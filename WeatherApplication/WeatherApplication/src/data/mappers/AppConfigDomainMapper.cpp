#include "AppConfigDomainMapper.h"

#include "ApiConfigDomainMapper.h"
#include "ServerHostConfigDomainMapper.h"
#include "CacheConfigDomainMapper.h"

AppConfig AppConfigDomainMapper::fromDto(const AppConfigDto &dto)
{
	return AppConfig(
	    ServerHostConfigDomainMapper::fromDto(dto.serverHostConfig),
        ApiConfigDomainMapper::fromDto(dto.apiConfig),
        CacheConfigDomainMapper::fromDto(dto.cacheConfig));
}
