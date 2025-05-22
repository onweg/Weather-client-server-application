#include "WeatherJsonConverter.h"

#include <QDate>

WeatherJsonConverter::WeatherJsonConverter(QObject *parent) : QObject(parent) {}

WeekWeatherDataDto
WeatherJsonConverter::parseWeekWeather(const QJsonObject &jsonObj)
{
	WeekWeatherDataDto weekData;
	if (!jsonObj.contains("list") || !jsonObj["list"].isArray())
	{
		weekData.messageError = "Invalid JSON: no 'list' field.";
		return weekData;
	}
	QString cityName = parseCityName(jsonObj);
	QJsonArray forecasts = jsonObj["list"].toArray();
	QMap<QString, WeatherDataDto> dailyData =
	    groupForecastsByDay(forecasts, cityName);
	weekData.city = cityName.toStdString();
	const QStringList keys = sortedKeys(dailyData);
	for (const QString &key : keys)
	{
		weekData.dailyWeather.push_back(dailyData[key]);
	}
	return weekData;
}

QString WeatherJsonConverter::parseCityName(const QJsonObject &jsonObj)
{
	if (jsonObj.contains("city") && jsonObj["city"].isObject())
	{
		return jsonObj["city"].toObject()["name"].toString();
	}
	return QString();
}

QMap<QString, WeatherDataDto>
WeatherJsonConverter::groupForecastsByDay(const QJsonArray &forecasts,
                                          const QString &cityName)
{
	QMap<QString, WeatherDataDto> dailyData;
	QDate currentDate = QDate::currentDate();
	for (const QJsonValue &forecastValue : forecasts)
	{
		if (!forecastValue.isObject())
			continue;
		processForecast(forecastValue.toObject(), cityName, currentDate,
		                dailyData);
	}
	return dailyData;
}

void WeatherJsonConverter::processForecast(
    const QJsonObject &forecast, const QString &cityName,
    const QDate &currentDate, QMap<QString, WeatherDataDto> &dailyData)
{
	QDateTime forecastTime = parseForecastTime(forecast);
	if (!forecastTime.isValid())
		return;
	QString dateKey = forecastTime.date().toString("yyyy-MM-dd");
	WeatherDataDto data = parseWeatherData(forecast, cityName, forecastTime);
	selectBestForecastForDay(data, dateKey, forecastTime, currentDate,
	                         dailyData);
}

QDateTime WeatherJsonConverter::parseForecastTime(const QJsonObject &forecast)
{
	QString dtTxt = forecast["dt_txt"].toString();
	return QDateTime::fromString(dtTxt, "yyyy-MM-dd HH:mm:ss");
}

WeatherDataDto
WeatherJsonConverter::parseWeatherData(const QJsonObject &forecast,
                                       const QString &cityName,
                                       const QDateTime &forecastTime)
{
	QJsonObject mainData = forecast["main"].toObject();
	QJsonObject windData =
	    forecast.contains("wind") ? forecast["wind"].toObject() : QJsonObject();
	WeatherDataDto data;
	data.city = cityName.toStdString();
	data.date = forecastTime.date().toString("yyyy-MM-dd").toStdString();
	data.temp = mainData["temp"].toDouble();
	data.feelsLike = mainData["feels_like"].toDouble();
	data.tempMin = mainData["temp_min"].toDouble();
	data.tempMax = mainData["temp_max"].toDouble();
	data.humidity = mainData["humidity"].toInt();
	data.pressure = mainData["pressure"].toInt();
	data.windSpeed = windData["speed"].toDouble();
	if (forecast.contains("weather") && forecast["weather"].isArray())
	{
		QJsonArray weatherArray = forecast["weather"].toArray();
		if (!weatherArray.isEmpty())
		{
			data.description = weatherArray.first()
			                       .toObject()["description"]
			                       .toString()
			                       .toStdString();
		}
	}
	return data;
}

void WeatherJsonConverter::selectBestForecastForDay(
    const WeatherDataDto &data, const QString &dateKey,
    const QDateTime &forecastTime, const QDate &currentDate,
    QMap<QString, WeatherDataDto> &dailyData)
{
	int hour = forecastTime.time().hour();
	if (forecastTime.date() == currentDate && hour >= 12)
	{
		if (!dailyData.contains(dateKey) ||
		    isBetterMatch(hour, dailyData, dateKey))
		{
			dailyData[dateKey] = data;
		}
	}
	else if (hour == 15)
	{
		dailyData[dateKey] = data;
	}
}

bool WeatherJsonConverter::isBetterMatch(
    int currentHour, const QMap<QString, WeatherDataDto> &dailyData,
    const QString &dateKey)
{
	QTime storedTime =
	    QDateTime::fromString(QString::fromStdString(dailyData[dateKey].date),
	                          "yyyy-MM-dd")
	        .time();
	int currentDiff = abs(15 - currentHour);
	int storedDiff = abs(15 - storedTime.hour());
	return currentDiff < storedDiff;
}

QStringList
WeatherJsonConverter::sortedKeys(const QMap<QString, WeatherDataDto> &dailyData)
{
	QStringList keys = dailyData.keys();
	std::sort(keys.begin(), keys.end());
	return keys;
}
