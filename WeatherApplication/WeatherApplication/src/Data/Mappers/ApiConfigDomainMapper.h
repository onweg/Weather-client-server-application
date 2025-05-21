#ifndef APICONFIGDOMAINMAPPER_H
#define APICONFIGDOMAINMAPPER_H

#include "../DtoModels/ApiConfigDto.h"
#include "../../Domain/Entities/ApiConfig.h"

class ApiConfigDomainMapper
{
public:
    static ApiConfigDto toDto(const ApiConfig& config);
    static ApiConfig fromDto(const ApiConfigDto& dto);
};

#endif // APICONFIGDOMAINMAPPER_H
