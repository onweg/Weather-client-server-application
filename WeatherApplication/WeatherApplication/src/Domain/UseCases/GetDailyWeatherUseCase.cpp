#include "GetDailyWeatherUseCase.h"

GetDailyWeatherUseCase::GetDailyWeatherUseCase(IApiWeatherSource *apiRepo, std::shared_ptr<IWeatherCacheSource> cacheRepo)
    :apiRepository_(apiRepo), cacheRepository_(std::move(cacheRepo))
{

}

QFuture<Result<WeatherData>> GetDailyWeatherUseCase::execute(const std::string& city, const std::string& date) {
    auto cachedResult = cacheRepository_->getDayWeather(city, date);
    if (cachedResult.isSuccess()) {
        // Вернуть готовый уже завершённый QFuture с результатом из кеша
        QFutureInterface<Result<WeatherData>> interface;
        interface.reportStarted();
        interface.reportResult(cachedResult);
        interface.reportFinished();
        return interface.future();
    }

    // Если в кеше нет — просто вернуть QFuture с результатом API напрямую
    // API возвращает QFuture<Result<WeekWeatherData>>, нужно преобразовать к QFuture<Result<WeatherData>>
    return QtConcurrent::run([this, city, date]() -> Result<WeatherData> {
        auto weekResult = apiRepository_->findWeatherDataByCity(city).result(); // blocking wait

        if (!weekResult.isSuccess()) {
            return Result<WeatherData>::failure(weekResult.errorMessage());
        }

        cacheRepository_->addWeekWeather(city, weekResult.value());

        auto updatedResult = cacheRepository_->getDayWeather(city, date);
        if (updatedResult.isSuccess()) {
            return updatedResult;
        }

        return Result<WeatherData>::failure("Погода на дату " + date + " не найдена даже после обновления");
    });
}

QFuture<Result<WeatherData>> GetDailyWeatherUseCase::execute(const std::string& city,
                                                             const std::string& date) {
    QFutureInterface<Result<WeatherData>> interface;
    interface.reportStarted();

    auto cacheResult = cacheRepository_->getDayWeather(city, date);
    if (cacheResult.isSuccess()) {
        interface.reportResult(cacheResult);
        interface.reportFinished();
        return interface.future();
    }

    auto apiFuture = apiRepository_->findWeatherDataByCity(city);

    QObject tmp;
    QObject::connect(&tmp, &QObject::destroyed, [apiFuture, this, city, date, interface]() mutable {
        auto weekResult = apiFuture.result();

        if (!weekResult.isSuccess()) {
            interface.reportResult(Result<WeatherData>::failure(weekResult.errorMessage()));
            interface.reportFinished();
            return;
        }

        cacheRepository_->addWeekWeather(city, weekResult.value());
        auto updated = cacheRepository_->getDayWeather(city, date);
        if (updated.isSuccess()) {
            interface.reportResult(updated);
        } else {
            interface.reportResult(Result<WeatherData>::failure("Погода на дату " + date + " не найдена даже после обновления"));
        }
        interface.reportFinished();
    });

    return interface.future();
}
