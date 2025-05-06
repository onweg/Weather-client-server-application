#ifndef WEEKWEATHERDATA_H
#define WEEKWEATHERDATA_H

#include <string>
#include <vector>
#include <algorithm>

#include "WeatherData.h"

struct WeekWeatherData {
    std::string city;
    std::vector<WeatherData> dailyWeather;
    std::string messageError;

    bool operator==(const WeekWeatherData &other) const;
    bool operator!=(const WeekWeatherData &other) const;
};

inline bool WeekWeatherData::operator==(const WeekWeatherData &other) const {
    return city == other.city &&
           messageError == other.messageError &&
           dailyWeather.size() == other.dailyWeather.size() &&
           std::equal(dailyWeather.begin(), dailyWeather.end(), other.dailyWeather.begin());
}

inline bool WeekWeatherData::operator!=(const WeekWeatherData &other) const {
    return !(*this == other);
}

#endif // WEEKWEATHERDATA_H
