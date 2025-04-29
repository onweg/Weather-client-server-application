#ifndef WEEKWEATHERDATA_H
#define WEEKWEATHERDATA_H

#include <QString>
#include <QList>
#include "WeatherData.h"

struct WeekWeatherData {
    QString city;
    QList<WeatherData> dailyWeather;
    QString messageError;

    bool operator==(const WeekWeatherData &other) const;
    bool operator!=(const WeekWeatherData &other) const;
};

inline bool WeekWeatherData::operator==(const WeekWeatherData &other) const {
    return city == other.city &&
           dailyWeather == other.dailyWeather &&
           messageError == other.messageError;
}

inline bool WeekWeatherData::operator!=(const WeekWeatherData &other) const {
    return !(*this == other);
}

#endif // WEEKWEATHERDATA_H
