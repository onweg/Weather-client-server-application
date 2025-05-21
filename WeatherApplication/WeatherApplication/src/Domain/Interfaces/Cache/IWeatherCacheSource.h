#ifndef IWEATHERCACHESOURCE_H
#define IWEATHERCACHESOURCE_H

#include <string>
#include "../../Entities/WeatherData.h"
#include "../../Entities/WeekWeatherData.h"
#include "../../Utils/Result.h"

class IWeatherCacheSource {
public:
    virtual ~IWeatherCacheSource() = default;
    virtual Result<WeatherData> getDayWeather(const std::string& city, const std::string& date) = 0;
    virtual Result<WeekWeatherData> getWeekWeather(const std::string& city) = 0;
    virtual void addWeekWeather(const std::string& city, const WeekWeatherData& data) = 0;
};

#endif // IWEATHERCACHESOURCE_H
