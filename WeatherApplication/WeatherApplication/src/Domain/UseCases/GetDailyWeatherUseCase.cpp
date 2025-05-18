#include "GetDailyWeatherUseCase.h"

GetDailyWeatherUseCase::GetDailyWeatherUseCase(IApiWeatherSource *apiRepo, std::shared_ptr<IWeatherCacheSource> cacheRepo)
    :apiRepository_(apiRepo), cacheRepository_(std::move(cacheRepo))
{

}

QFuture<Result<WeatherData>> GetDailyWeatherUseCase::execute(const std::string& city, const std::string& date) {
    auto cachedResult = cacheRepository_->getDayWeather(city, date);
    if (cachedResult.isSuccess()) {
        // Вернуть готовый уже завершённый QFuture с результатом из кеша
        return QtFuture::makeReadyFuture(Result<WeatherData>::success(cachedResult.value()));
    }

    return apiRepository_->findWeatherDataByCity(city);
}
