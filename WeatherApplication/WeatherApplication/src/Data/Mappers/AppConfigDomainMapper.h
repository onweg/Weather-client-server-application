#ifndef APPCONFIGDOMAINMAPPER_H
#define APPCONFIGDOMAINMAPPER_H

#include "../../Domain/Entities/AppConfig.h"
#include "../DtoModels/AppConfigDto.h"

class AppConfigDomainMapper
{
  public:
	static AppConfigDto toDto(const AppConfig &config);
	static AppConfig fromDto(const AppConfigDto &dto);
};

#endif // APPCONFIGDOMAINMAPPER_H
