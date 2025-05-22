#ifndef WEATHERDATADTO_H
#define WEATHERDATADTO_H

#include <string>

struct WeatherDataDto
{
	double lat;
	double lon;
	std::string city;
	std::string date;
	std::string description;
	double temp;
	double feelsLike;
	double tempMax;
	double tempMin;
	double windSpeed;
	int humidity;
	int pressure;
	std::string messageError;
};

#endif // WEATHERDATADTO_H
