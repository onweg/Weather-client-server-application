#include "GetWeeklyWeatherUseCase.h"

GetWeeklyWeatherUseCase::GetWeeklyWeatherUseCase(IApiWeatherSource *apiRepo, std::shared_ptr<IWeatherCacheSource> cacheRepo)
    :apiRepository_(apiRepo), cacheRepository_(std::move(cacheRepo))
{

}

QFuture<Result<WeekWeatherData> > GetWeeklyWeatherUseCase::execute(const std::string &city)
{
    auto cachedResult = cacheRepository_->getWeekWeather(city);
    if (cachedResult.isSuccess()) {
        // Вернуть готовый уже завершённый QFuture с результатом из кеша
        return QtFuture::makeReadyFuture(Result<WeekWeatherData>::success(cachedResult.value()));
    }

    return apiRepository_->findWeatherDataByCity(city);
}

