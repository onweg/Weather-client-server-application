#include "ApiConfigDomainMapper.h"

ApiConfigDto ApiConfigDomainMapper::toDto(const ApiConfig& config)
{
    return {
        config.getUrlFindCityByName(),
        config.getUrlFindWeatherByCoordinates(),
        config.getKey()
    };
}

ApiConfig ApiConfigDomainMapper::fromDto(const ApiConfigDto& dto)
{
    return ApiConfig(
        dto.urlFindCityByName,
        dto.urlFindWeatherByCoordinates,
        dto.key
    );
}
