#ifndef WEATHERDATAMAPPER_H
#define WEATHERDATAMAPPER_H

#include "../../Domain/Entities/WeatherData.h"
#include "../DtoModels/WeatherDataDto.h"

class WeatherDomainMapper {
public:
    static WeatherDataDto toDto(const WeatherData& domain);
    static WeatherData fromDto(const WeatherDataDto& dto);
};

#endif // WEATHERDATAMAPPER_H
