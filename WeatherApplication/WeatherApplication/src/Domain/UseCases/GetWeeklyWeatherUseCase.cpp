#include "GetWeeklyWeatherUseCase.h"

GetWeeklyWeatherUseCase::GetWeeklyWeatherUseCase(IApiWeatherSource *apiRepo, std::shared_ptr<IWeatherCacheSource> cacheRepo)
    :apiRepository_(apiRepo), cacheRepository_(std::move(cacheRepo))
{

}

QFuture<Result<WeekWeatherData> > GetWeeklyWeatherUseCase::execute(const std::string &city)
{
    auto cached = cacheRepository_->getWeekWeather(city);
    if (cached.isSuccess()) {
        callback(cached);
        return;
    }

    apiRepository_->findWeatherDataByCity(city, [this, city, callback](Result<WeekWeatherData> apiResult) {
        if (!apiResult.isSuccess()) {
            callback(Result<WeekWeatherData>::failure(apiResult.errorMessage()));
            return;
        }

        cacheRepository_->addWeekWeather(city, apiResult.value());
        callback(apiResult);
    });
}

