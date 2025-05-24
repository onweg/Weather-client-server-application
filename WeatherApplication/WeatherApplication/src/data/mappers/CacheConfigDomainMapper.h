#ifndef CACHECONFIGDOMAINMAPPER_H
#define CACHECONFIGDOMAINMAPPER_H

#include "../../infrastructure/config/CacheConfig.h"
#include "../dtomodels/CacheConfigDto.h"

class CacheConfigDomainMapper
{
public:
    static CacheConfigDto toDto(const CacheConfig &config);
    static CacheConfig fromDto(const CacheConfigDto &dto);
};

#endif // CACHECONFIGDOMAINMAPPER_H
