#ifndef IWEATHERDAYCACHEDATASOUTCE_H
#define IWEATHERDAYCACHEDATASOUTCE_H

#include <string>
#include "../../Entities/WeatherData.h"
#include "../../Utils/Result.h"

class IWeatherDayCacheDataSource {
public:
    virtual ~IWeatherDayCacheDataSource() = default;
    virtual Result<WeatherData> getDayWeather(const std::string& city, const std::string& date) = 0;
};

#endif // IWEATHERDAYCACHEDATASOUTCE_H