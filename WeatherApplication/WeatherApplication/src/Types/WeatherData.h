#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <QString>
#include <QDate>

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
};

Q_DECLARE_METATYPE(WeatherData);

#endif // WEATHERDATA_H
