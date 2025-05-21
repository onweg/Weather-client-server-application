#include "AppConfigDomainMapper.h"
#include "ServerHostConfigDomainMapper.h"
#include "ApiConfigDomainMapper.h"

AppConfigDto AppConfigDomainMapper::toDto(const AppConfig& config)
{
    return {
        ServerHostConfigDomainMapper::toDto(config.getServerHostConfig()),
        ApiConfigDomainMapper::toDto(config.getApiConfig())
    };
}

AppConfig AppConfigDomainMapper::fromDto(const AppConfigDto& dto)
{
    return AppConfig(
        ServerHostConfigDomainMapper::fromDto(dto.serverHostConfig),
        ApiConfigDomainMapper::fromDto(dto.apiConfig)
    );
}
