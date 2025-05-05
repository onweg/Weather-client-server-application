#ifndef IWEATHERREPOSITORY_H
#define IWEATHERREPOSITORY_H

#include <string>
#include <functional>

#include "../../Entities/WeatherData.h"
#include "../../Entities/WeekWeatherData.h
#include "../../Utils/Result.h"

class IWeatherRepository {
public:
    virtual ~IWeatherRepository() = default;
    virtual void findWeather(const std::string city, const std::string date, std::function<void(Result<WeatherData>)> callback) = 0;
    virtual void findWeekWeather(const std::string city, std::function<void(Result<WeekWeatherData>)> callback) = 0;


};

#endif // IWEATHERREPOSITORY_H
