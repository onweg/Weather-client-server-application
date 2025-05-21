#ifndef APPCONFIGDOMAINMAPPER_H
#define APPCONFIGDOMAINMAPPER_H

#include "../DtoModels/AppConfigDto.h"
#include "../../Domain/Entities/AppConfig.h"

class AppConfigDomainMapper
{
public:
    static AppConfigDto toDto(const AppConfig& config);
    static AppConfig fromDto(const AppConfigDto& dto);
};

#endif // APPCONFIGDOMAINMAPPER_H
