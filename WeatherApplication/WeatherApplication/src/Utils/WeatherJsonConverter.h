#ifndef WEATHERJSONCONVERTER_H
#define WEATHERJSONCONVERTER_H

#include "../Domain/Entities/WeekWeatherData.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QMap>
#include <QObject>

class WeatherJsonConverter : public QObject {
 Q_OBJECT
public:
 explicit WeatherJsonConverter(QObject *parent = nullptr);

 static WeekWeatherData parseWeekWeather(const QJsonObject &jsonObj);
};

#endif	// WEATHERJSONCONVERTER_H
