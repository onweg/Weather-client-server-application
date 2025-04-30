#ifndef WEATHERJSONCONVERTER_H
#define WEATHERJSONCONVERTER_H

#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include <QMap>
#include "../Types/WeekWeatherData.h"

class WeatherJsonConverter : public QObject
{
    Q_OBJECT
public:
    explicit WeatherJsonConverter(QObject *parent = nullptr);

    static WeekWeatherData parseWeekWeather(const QJsonObject &jsonObj);

};

#endif // WEATHERJSONCONVERTER_H
