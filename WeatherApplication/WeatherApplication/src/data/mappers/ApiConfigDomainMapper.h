#ifndef APICONFIGDOMAINMAPPER_H
#define APICONFIGDOMAINMAPPER_H

#include "../../domain/entities/ApiConfig.h"
#include "../dtomodels/ApiConfigDto.h"

class ApiConfigDomainMapper
{
  public:
	static ApiConfig fromDto(const ApiConfigDto &dto);
};

#endif // APICONFIGDOMAINMAPPER_H
