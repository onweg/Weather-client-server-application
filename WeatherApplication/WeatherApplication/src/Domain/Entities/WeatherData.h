#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <string>
#include <cmath>

inline bool areAlmostEqual(double a, double b, double epsilon = 1e-9) {
    return std::fabs(a - b) <= epsilon * std::max(std::fabs(a), std::fabs(b));
}

struct WeatherData
{
    double lat = 0.0;
    double lon = 0.0;
    std::string city = "...";
    std::string date;
    std::string description = "...";
    double temp = 0.0;
    double feels_like = 0.0;
    double temp_max = 0.0;
    double temp_min = 0.0;
    double wind_speed = 0.0;
    int humidity = 0;
    int pressure = 0;
    std::string messageError;

    bool operator==(const WeatherData &other) const;
    bool operator!=(const WeatherData &other) const;
};

inline bool WeatherData::operator==(const WeatherData &other) const {
    return city == other.city &&
           date == other.date &&
           description == other.description &&
           areAlmostEqual(lat, other.lat) &&
           areAlmostEqual(lon, other.lon) &&
           areAlmostEqual(temp, other.temp) &&
           areAlmostEqual(feels_like, other.feels_like) &&
           areAlmostEqual(temp_max, other.temp_max) &&
           areAlmostEqual(temp_min, other.temp_min) &&
           areAlmostEqual(wind_speed, other.wind_speed) &&
           humidity == other.humidity &&
           pressure == other.pressure;
}

inline bool WeatherData::operator!=(const WeatherData &other) const {
    return !(*this == other);
}

#endif // WEATHERDATA_H
