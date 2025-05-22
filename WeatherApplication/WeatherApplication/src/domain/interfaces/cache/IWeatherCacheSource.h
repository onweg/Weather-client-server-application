#ifndef IWEATHERCACHESOURCE_H
#define IWEATHERCACHESOURCE_H

#include <string>

#include "../../entities/WeatherData.h"
#include "../../entities/WeekWeatherData.h"
#include "../../utils/Result.h"

class IWeatherCacheSource
{
  public:
	virtual ~IWeatherCacheSource() = default;
	virtual Result<WeatherData> getDayWeather(const std::string &city,
	                                          const std::string &date) = 0;
	virtual Result<WeekWeatherData> getWeekWeather(const std::string &city) = 0;
	virtual void addWeekWeather(const std::string &city,
	                            const WeekWeatherData &data) = 0;
};

#endif // IWEATHERCACHESOURCE_H
