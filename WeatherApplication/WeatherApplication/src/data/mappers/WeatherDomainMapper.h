#ifndef WEATHERDOMAINMAPPER_H
#define WEATHERDOMAINMAPPER_H

#include "../../domain/entities/WeatherData.h"
#include "../dtomodels/WeatherDataDto.h"

class WeatherDomainMapper
{
  public:
	static WeatherDataDto toDto(const WeatherData &domain);
	static WeatherData fromDto(const WeatherDataDto &dto);
};

#endif // WEATHERDOMAINMAPPER_H
