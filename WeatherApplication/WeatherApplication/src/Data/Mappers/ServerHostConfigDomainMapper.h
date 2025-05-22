#ifndef SERVERHOSTCONFIGDOMAINMAPPER_H
#define SERVERHOSTCONFIGDOMAINMAPPER_H

#include "../../Domain/Entities/ServerHostConfig.h"
#include "../DtoModels/ServerHostConfigDto.h"

class ServerHostConfigDomainMapper
{
  public:
	static ServerHostConfigDto toDto(const ServerHostConfig &config);
	static ServerHostConfig fromDto(const ServerHostConfigDto &dto);
};

#endif // SERVERHOSTCONFIGDOMAINMAPPER_H
