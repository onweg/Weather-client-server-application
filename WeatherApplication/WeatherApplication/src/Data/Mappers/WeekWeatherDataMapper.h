#ifndef WEEKWEATHERDATAMAPPER_H
#define WEEKWEATHERDATAMAPPER_H

#include "../../Domain/Entities/WeekWeatherData.h"
#include "../DtoModels/WeekWeatherDataDto.h"

class WeekWeatherDomainMapper {
public:
    static WeekWeatherDataDto toDto(const WeekWeatherData& domain);
    static WeekWeatherData fromDto(const WeekWeatherDataDto& dto);
};

#endif // WEEKWEATHERDATAMAPPER_H
