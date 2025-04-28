#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <QString>
#include <QDate>
#include <QVariantMap>

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

    QVariantMap toVariantMap() const {
        QVariantMap map;
        map["lat"] = lat;
        map["lon"] = lon;
        map["city"] = city;
        map["date"] = date.toString("yyyy-MM-dd");
        map["description"] = description;
        map["temp"] = temp;
        map["feels_like"] = feels_like;
        map["temp_max"] = temp_max;
        map["temp_min"] = temp_min;
        map["wind_speed"] = wind_speed;
        map["humidity"] = humidity;
        map["pressure"] = pressure;
        map["messageError"] = messageError;
        return map;
    }
};

Q_DECLARE_METATYPE(WeatherData);

#endif // WEATHERDATA_H
