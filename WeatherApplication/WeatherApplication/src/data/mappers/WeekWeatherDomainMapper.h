#ifndef WEEKWEATHERDOMAINMAPPER_H
#define WEEKWEATHERDOMAINMAPPER_H

#include "../../domain/entities/WeekWeatherData.h"
#include "../dtomodels/WeekWeatherDataDto.h"

class WeekWeatherDomainMapper
{
  public:
	static WeekWeatherDataDto toDto(const WeekWeatherData &domain);
	static WeekWeatherData fromDto(const WeekWeatherDataDto &dto);
};

#endif // WEEKWEATHERDOMAINMAPPER_H
