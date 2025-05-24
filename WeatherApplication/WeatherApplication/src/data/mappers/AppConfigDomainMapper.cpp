#include "AppConfigDomainMapper.h"

#include "ApiConfigDomainMapper.h"
#include "CacheConfigDomainMapper.h"
#include "ServerHostConfigDomainMapper.h"

AppConfig AppConfigDomainMapper::fromDto(const AppConfigDto &dto)
{
	return AppConfig(
	    ServerHostConfigDomainMapper::fromDto(dto.serverHostConfig),
	    ApiConfigDomainMapper::fromDto(dto.apiConfig),
	    CacheConfigDomainMapper::fromDto(dto.cacheConfig));
}
