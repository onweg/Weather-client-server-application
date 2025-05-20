#ifndef WEATHERJSONCONVERTER_H
#define WEATHERJSONCONVERTER_H

#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include <QMap>
#include "../Domain/Entities/WeekWeatherData.h"

class WeatherJsonConverter : public QObject
{
    Q_OBJECT
public:
    explicit WeatherJsonConverter(QObject *parent = nullptr);

    static WeekWeatherData parseWeekWeather(const QJsonObject &jsonObj);

private:
    static QString parseCityName(const QJsonObject& jsonObj);
    static QMap<QString, WeatherData> groupForecastsByDay(const QJsonArray& forecasts, const QString& cityName);
    static void processForecast(const QJsonObject& forecast, const QString& cityName, const QDate& currentDate, QMap<QString, WeatherData>& dailyData);
    static QDateTime parseForecastTime(const QJsonObject& forecast);
    static WeatherData parseWeatherData(const QJsonObject& forecast, const QString& cityName, const QDateTime& forecastTime);
    static void selectBestForecastForDay(const WeatherData& data, const QString& dateKey, const QDateTime& forecastTime, const QDate& currentDate, QMap<QString, WeatherData>& dailyData);
    static bool isBetterMatch(int currentHour, const QMap<QString, WeatherData>& dailyData, const QString& dateKey);
    static QStringList sortedKeys(const QMap<QString, WeatherData>& dailyData);

};

#endif // WEATHERJSONCONVERTER_H
