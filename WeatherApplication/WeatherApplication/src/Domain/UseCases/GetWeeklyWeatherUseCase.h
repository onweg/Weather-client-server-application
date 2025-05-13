#ifndef GETWEEKLYWEATHERUSECASE_H
#define GETWEEKLYWEATHERUSECASE_H

#include <QDate>
#include <functional>
#include <memory>
#include <string>

#include "../Entities/WeekWeatherData.h"
#include "../Interfaces/Api/IApiWeatherSource.h"
#include "../Interfaces/Cache/IWeatherCacheSource.h"
#include "../Utils/Result.h"

class GetWeeklyWeatherUseCase {
  public:
    explicit GetWeeklyWeatherUseCase(IApiWeatherSource *apiRepo,
        std::shared_ptr<IWeatherCacheSource> cacheRepo);

    void execute(const std::string &city,
        std::function<void(Result<WeekWeatherData>)> callback);

  private:
    IApiWeatherSource *apiRepository_;
    std::shared_ptr<IWeatherCacheSource> cacheRepository_;
};

#endif // GETWEEKLYWEATHERUSECASE_H
