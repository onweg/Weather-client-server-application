#ifndef IWEATHERREPOSITORY_H
#define IWEATHERREPOSITORY_H

#include <QFuture>
#include <memory>
#include <string>

#include "../../entities/WeatherData.h"
#include "../../entities/WeekWeatherData.h"
#include "../../utils/Result.h"

class IWeatherRepository
{
  public:
	virtual ~IWeatherRepository() = default;
	virtual QFuture<Result<WeatherData>>
	getDailyWeather(const std::string &city, const std::string &date) = 0;
	virtual QFuture<Result<WeekWeatherData>>
	getWeeklyWeather(const std::string &city) = 0;
};

#endif // IWEATHERREPOSITORY_H
