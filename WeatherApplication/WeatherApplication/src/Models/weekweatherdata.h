#ifndef WEEKWEATHERDATA_H
#define WEEKWEATHERDATA_H

#include "weatherdata.h"
#include <QList>

struct WeekWeatherData
{
    QString city;
    QList<WeatherData> dailyWeather;
	QString messageError;

    QVariantMap toVariantMap() const {
        QVariantMap map;
        map["city"] = city;

        QVariantList dailyWeatherList;
        for (const auto &data : dailyWeather) {
            dailyWeatherList.append(data.toVariantMap());
        }
        map["dailyWeather"] = dailyWeatherList;

        map["messageError"] = messageError;
        return map;
    }
};
Q_DECLARE_METATYPE(WeekWeatherData);
#endif // WEEKWEATHERDATA_H
