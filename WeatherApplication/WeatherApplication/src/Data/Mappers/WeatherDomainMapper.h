#ifndef WEATHERDOMAINMAPPER_H
#define WEATHERDOMAINMAPPER_H

#include "../../Domain/Entities/WeatherData.h"
#include "../DtoModels/WeatherDataDto.h"

class WeatherDomainMapper {
public:
    static WeatherDataDto toDto(const WeatherData& domain);
    static WeatherData fromDto(const WeatherDataDto& dto);
};

#endif // WEATHERDOMAINMAPPER_H
