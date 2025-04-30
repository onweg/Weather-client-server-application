#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <QString>
#include <QDate>
#include <QtMath>

struct WeatherData
{
    double lat = 0.0;
    double lon = 0.0;
    QString city = "...";
    QDate date;
    QString description = "...";
    double temp = 0.0;
    double feels_like = 0.0;
    double temp_max = 0.0;
    double temp_min = 0.0;
    double wind_speed = 0.0;
    int humidity = 0;
    int pressure = 0;
    QString messageError;

    bool operator==(const WeatherData &other) const;
    bool operator!=(const WeatherData &other) const;
};

inline bool WeatherData::operator==(const WeatherData &other) const {
    return city == other.city &&
           date == other.date &&
           description == other.description &&
           qFuzzyCompare(temp, other.temp) &&
           qFuzzyCompare(feels_like, other.feels_like) &&
           qFuzzyCompare(wind_speed, other.wind_speed) &&
           humidity == other.humidity &&
           pressure == other.pressure;
}

inline bool WeatherData::operator!=(const WeatherData &other) const {
    return !(*this == other);
}

#endif // WEATHERDATA_H
