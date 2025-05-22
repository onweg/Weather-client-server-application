#ifndef WEATHERJSONCONVERTER_H
#define WEATHERJSONCONVERTER_H

#include <QJsonArray>
#include <QJsonObject>
#include <QMap>
#include <QObject>

#include "../Data/DtoModels/WeekWeatherDataDto.h"

class WeatherJsonConverter : public QObject
{
	Q_OBJECT
  public:
	explicit WeatherJsonConverter(QObject *parent = nullptr);

	static WeekWeatherDataDto parseWeekWeather(const QJsonObject &jsonObj);

  private:
	static QString parseCityName(const QJsonObject &jsonObj);
	static QMap<QString, WeatherDataDto>
	groupForecastsByDay(const QJsonArray &forecasts, const QString &cityName);
	static void processForecast(const QJsonObject &forecast,
	                            const QString &cityName,
	                            const QDate &currentDate,
	                            QMap<QString, WeatherDataDto> &dailyData);
	static QDateTime parseForecastTime(const QJsonObject &forecast);
	static WeatherDataDto parseWeatherData(const QJsonObject &forecast,
	                                       const QString &cityName,
	                                       const QDateTime &forecastTime);
	static void
	selectBestForecastForDay(const WeatherDataDto &data, const QString &dateKey,
	                         const QDateTime &forecastTime,
	                         const QDate &currentDate,
	                         QMap<QString, WeatherDataDto> &dailyData);
	static bool isBetterMatch(int currentHour,
	                          const QMap<QString, WeatherDataDto> &dailyData,
	                          const QString &dateKey);
	static QStringList
	sortedKeys(const QMap<QString, WeatherDataDto> &dailyData);
};

#endif // WEATHERJSONCONVERTER_H
