#include "CacheConfigDomainMapper.h"

CacheConfigDto CacheConfigDomainMapper::toDto(const CacheConfig &config)
{
    return {config.getMaxMemoryBytes()};
}

CacheConfig CacheConfigDomainMapper::fromDto(const CacheConfigDto &dto)
{
    return CacheConfig(dto.maxMemoryBytes);
}
