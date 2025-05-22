#ifndef APICONFIGDOMAINMAPPER_H
#define APICONFIGDOMAINMAPPER_H

#include "../../Domain/Entities/ApiConfig.h"
#include "../DtoModels/ApiConfigDto.h"

class ApiConfigDomainMapper
{
  public:
	static ApiConfigDto toDto(const ApiConfig &config);
	static ApiConfig fromDto(const ApiConfigDto &dto);
};

#endif // APICONFIGDOMAINMAPPER_H
