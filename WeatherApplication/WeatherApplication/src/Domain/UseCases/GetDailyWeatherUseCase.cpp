#include "GetDailyWeatherUseCase.h"

GetDailyWeatherUseCase::GetDailyWeatherUseCase(IApiWeatherSource *apiRepo, std::shared_ptr<IWeatherCacheSource> cacheRepo)
    :apiRepository_(apiRepo), cacheRepository_(std::move(cacheRepo))
{

}

void GetDailyWeatherUseCase::execute(const std::string& city, const std::string& date, std::function<void(Result<WeatherData>)> callback
) {
    auto result = cacheRepository_->getDayWeather(city, date);
    if (result.isSuccess()) {
        callback(result);
        return;
    }
    apiRepository_->findWeatherDataByCity(city, [this, city, date, callback](Result<WeekWeatherData> weekResult) {
        if (!weekResult.isSuccess()) {
            callback(Result<WeatherData>::failure(weekResult.errorMessage()));
            return;
        }
        cacheRepository_->addWeekWeather(city, weekResult.value());
        auto updatedResult = cacheRepository_->getDayWeather(city, date);
        if (updatedResult.isSuccess()) {
            callback(updatedResult);
        } else {
            callback(Result<WeatherData>::failure("Погода на дату " + date + " не найдена даже после обновления"));
        }
    });
}
