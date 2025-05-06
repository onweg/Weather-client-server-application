#ifndef IWEATHERWEEKCACHEDATASOUTCE_H
#define IWEATHERWEEKCACHEDATASOUTCE_H

#include <string>
#include "../../Entities/WeekWeatherData.h"
#include "../../Utils/Result.h"

class IWeatherWeekCacheDataSource {
public:
    virtual ~IWeatherWeekCacheDataSource() = default;
    virtual Result<WeekWeatherData> getWeekWeather(const std::string& city) = 0;
};

#endif // IWEATHERWEEKCACHEDATASOUTCE_H