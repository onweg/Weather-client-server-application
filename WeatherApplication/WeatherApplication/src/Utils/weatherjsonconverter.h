#ifndef WEATHERJSONCONVERTER_H
#define WEATHERJSONCONVERTER_H

#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include <QMap>
#include "../Models/weekweatherdata.h"
#include "../Models/authorizationreply.h"

class WeatherJsonConverter : public QObject
{
    Q_OBJECT
public:
    explicit WeatherJsonConverter(QObject *parent = nullptr);

    static WeekWeatherData parseWeekWeather(const QJsonObject &jsonObj);
    static AuthorizationReply parseAuthorizationReply(const QJsonObject &jsonObj);

};

#endif // WEATHERJSONCONVERTER_H
// #ifndef WEATHERJSONCONVERTER_H
// #define WEATHERJSONCONVERTER_H

// #include <QObject>
// #include <QJsonObject>
// #include <QJsonArray>
// #include "../Models/WeatherData.h"
// #include "../Models/WeatherWeekData.h"
// #include "../Models/UserData.h"
// #include "../Models/ApiReply.h"

// class WeatherJsonConverter : public QObject
// {
//     Q_OBJECT
// public:
//     explicit WeatherJsonConverter(QObject *parent = nullptr);

//     static WeatherData parseWeatherDay(const QJsonObject &jsonObj);
//     static WeatherWeekData parseWeatherWeek(const QJsonObject &jsonObj);
//     static UserData parseUserData(const QJsonObject &jsonObj);
//     static ApiReply parseApiReply(const QJsonObject &jsonObj);

// private:
//     static WeatherData createWeatherDataFromForecast(const QJsonObject &forecast);
// };

// #endif // WEATHERJSONCONVERTER_H
