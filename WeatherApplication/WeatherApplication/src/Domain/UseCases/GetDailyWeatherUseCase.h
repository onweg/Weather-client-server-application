#ifndef GETDAILYWEATHERUSECASE_H
#define GETDAILYWEATHERUSECASE_H

#include <string>
#include <functional>
#include <memory>
#include "../Entities/WeatherData.h"
#include "../Interfaces/Api/IApiWeatherSource.h"
#include "../Interfaces/Cache/IWeatherCacheSource.h"

class GetDailyWeatherUseCase {
public:
    explicit GetDailyWeatherUseCase(IApiWeatherSource* apiRepo, std::shared_ptr<IWeatherCacheSource> cacheRepo);

    QFuture<Result<WeekWeatherData>> execute(const std::string& city, const std::string& date);

private:
    IApiWeatherSource* apiRepository_;
    std::shared_ptr<IWeatherCacheSource> cacheRepository_;
};

#endif // GETDAILYWEATHERUSECASE_H
