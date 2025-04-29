#ifndef WEEKWEATHERDATA_H
#define WEEKWEATHERDATA_H

#include "WeatherData.h"
#include <QList>

struct WeekWeatherData
{
    QString city;
    QList<WeatherData> dailyWeather;
	QString messageError;
};
Q_DECLARE_METATYPE(WeekWeatherData);
#endif // WEEKWEATHERDATA_H
