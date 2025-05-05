#ifndef WEEKWEATHERDTO_H
#define WEEKWEATHERDTO_H

#include <string>
#include <vector>
#include "WeatherDataDto.h"

struct WeekWeatherDataDto {
    std::string city;
    std::vector<WeatherDataDto> dailyWeather;
    std::string messageError;

    WeekWeatherDataDto(
        const std::string& city_ = "",
        const std::vector<WeatherDataDto>& weather_ = {},
        const std::string& error_ = ""
    ) : city(city_), dailyWeather(weather_), messageError(error_) {}
};

#endif // WEEKWEATHERDTO_H
