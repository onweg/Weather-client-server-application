#ifndef APICONFIGDTO_H
#define APICONFIGDTO_H

#include <string>

struct ApiConfigDto
{
	std::string urlFindCityByName;
	std::string urlFindWeatherByCoordinates;
	std::string key;
};

#endif // APICONFIGDTO_H
