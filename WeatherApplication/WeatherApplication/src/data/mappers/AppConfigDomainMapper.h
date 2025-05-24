#ifndef APPCONFIGDOMAINMAPPER_H
#define APPCONFIGDOMAINMAPPER_H

#include "../../domain/entities/AppConfig.h"
#include "../dtomodels/AppConfigDto.h"

class AppConfigDomainMapper
{
  public:
	static AppConfig fromDto(const AppConfigDto &dto);
};

#endif // APPCONFIGDOMAINMAPPER_H
