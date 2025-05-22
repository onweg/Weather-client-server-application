#ifndef WEEKWEATHERDTO_H
#define WEEKWEATHERDTO_H

#include <string>
#include <vector>

#include "WeatherDataDto.h"

struct WeekWeatherDataDto
{
	std::string city;
	std::vector<WeatherDataDto> dailyWeather;
	std::string messageError;
};

#endif // WEEKWEATHERDTO_H
