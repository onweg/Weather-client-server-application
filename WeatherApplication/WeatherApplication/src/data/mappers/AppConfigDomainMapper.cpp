#include "AppConfigDomainMapper.h"

#include "ApiConfigDomainMapper.h"
#include "ServerHostConfigDomainMapper.h"
#include "CacheConfigDomainMapper.h"

AppConfigDto AppConfigDomainMapper::toDto(const AppConfig &config)
{
	return {ServerHostConfigDomainMapper::toDto(config.getServerHostConfig()),
            ApiConfigDomainMapper::toDto(config.getApiConfig()),
            CacheConfigDomainMapper::toDto(config.getCacheConfig())};
}

AppConfig AppConfigDomainMapper::fromDto(const AppConfigDto &dto)
{
	return AppConfig(
	    ServerHostConfigDomainMapper::fromDto(dto.serverHostConfig),
        ApiConfigDomainMapper::fromDto(dto.apiConfig),
        CacheConfigDomainMapper::fromDto(dto.cacheConfig));
}
