#ifndef SERVERHOSTCONFIGDOMAINMAPPER_H
#define SERVERHOSTCONFIGDOMAINMAPPER_H

#include "../DtoModels/ServerHostConfigDto.h"
#include "../../Domain/Entities/ServerHostConfig.h"

class ServerHostConfigDomainMapper
{
public:
    static ServerHostConfigDto toDto(const ServerHostConfig& config);
    static ServerHostConfig fromDto(const ServerHostConfigDto& dto);
};

#endif // SERVERHOSTCONFIGDOMAINMAPPER_H
