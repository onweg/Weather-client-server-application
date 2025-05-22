#ifndef WEEKWEATHERDATA_H
#define WEEKWEATHERDATA_H

#include <string>
#include <vector>

#include "WeatherData.h"

class WeekWeatherData
{
  public:
	WeekWeatherData();
	WeekWeatherData(const std::string &city,
	                const std::vector<WeatherData> &dailyWeather,
	                const std::string &messageError);

	const std::string &getCity() const;
	void setCity(const std::string &city);

	const std::vector<WeatherData> &getDailyWeather() const;
	void setDailyWeather(const std::vector<WeatherData> &dailyWeather);

	const std::string &getMessageError() const;
	void setMessageError(const std::string &messageError);

	bool operator==(const WeekWeatherData &other) const;
	bool operator!=(const WeekWeatherData &other) const;

  private:
	std::string m_city;
	std::vector<WeatherData> m_dailyWeather;
	std::string m_messageError;
};

#endif // WEEKWEATHERDATA_H
