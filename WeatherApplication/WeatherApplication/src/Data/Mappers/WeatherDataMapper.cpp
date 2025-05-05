#include "WeatherDataMapper.h"

WeatherDataDto WeatherDomainMapper::toDto(const WeatherData& domain) {
    return WeatherDataDto{
        domain.lat,
        domain.lon,
        domain.city,
        domain.date,
        domain.description,
        domain.temp,
        domain.feels_like,
        domain.temp_max,
        domain.temp_min,
        domain.wind_speed,
        domain.humidity,
        domain.pressure,
        domain.messageError
    };
}

WeatherData WeatherDomainMapper::fromDto(const WeatherDataDto& dto) {
    return WeatherData{
        dto.lat,
        dto.lon,
        dto.city,
        dto.date,
        dto.description,
        dto.temp,
        dto.feels_like,
        dto.temp_max,
        dto.temp_min,
        dto.wind_speed,
        dto.humidity,
        dto.pressure,
        dto.messageError
    };
}
