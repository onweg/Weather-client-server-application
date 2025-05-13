#ifndef WEATHERDATADTO_H
#define WEATHERDATADTO_H

#include <string>

struct WeatherDataDto {
    double lat;
    double lon;
    std::string city;
    std::string date;
    std::string description;
    double temp;
    double feels_like;
    double temp_max;
    double temp_min;
    double wind_speed;
    int humidity;
    int pressure;
    std::string messageError;
};

#endif // WEATHERDATADTO_H
