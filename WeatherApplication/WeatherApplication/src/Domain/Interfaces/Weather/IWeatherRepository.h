#ifndef IWEATHERREPOSITORY_H
#define IWEATHERREPOSITORY_H

#include "../../Utils/Result.h"
#include "../../Entities/WeatherData.h"
#include "../../Entities/WeekWeatherData.h"
#include <string>
#include <memory>
#include <QFuture>

class IWeatherRepository {
public:
    virtual ~IWeatherRepository() = default;

    virtual QFuture<Result<WeatherData>> getDailyWeather(const std::string& city, const std::string& date) = 0;
    virtual QFuture<Result<WeekWeatherData>> getWeeklyWeather(const std::string& city) = 0;
};

#endif // IWEATHERREPOSITORY_H
