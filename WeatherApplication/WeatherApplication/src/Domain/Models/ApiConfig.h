#ifndef APICONFIG_H
#define APICONFIG_H

#include <string>

struct ApiConfig {
    std::string urlFindCityByName;
    std::string urlFindWeatherByCoordinates;
    std::string key;
};

#endif // APICONFIG_H
