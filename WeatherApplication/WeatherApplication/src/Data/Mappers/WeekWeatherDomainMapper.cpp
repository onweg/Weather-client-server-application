#include "WeekWeatherDomainMapper.h"
#include "WeatherDomainMapper.h"

WeekWeatherDataDto WeekWeatherDomainMapper::toDto(const WeekWeatherData& domain) {
    std::vector<WeatherDataDto> dailyDtos;
    for (const auto& weather : domain.dailyWeather) {
        dailyDtos.push_back(WeatherDomainMapper::toDto(weather));
    }
    return WeekWeatherDataDto{
        domain.city,
        dailyDtos,
        domain.messageError
    };
}

WeekWeatherData WeekWeatherDomainMapper::fromDto(const WeekWeatherDataDto& dto) {
    std::vector<WeatherData> dailyWeather;
    for (const auto& weatherDto : dto.dailyWeather) {
        dailyWeather.push_back(WeatherDomainMapper::fromDto(weatherDto));
    }
    return WeekWeatherData{
        dto.city,
        dailyWeather,
        dto.messageError
    };
}
