#include "WeatherRepository.h"
#include <QFutureWatcher>
#include <QFutureInterface>
#include "../../../Domain/Utils/MakeReadyFuture.h"

WeatherRepository::WeatherRepository(std::shared_ptr<IWeatherCacheSource> cache, IApiWeatherSource *api, QObject *parent)
    :QObject(parent), cache_(std::move(cache)), api_(api)
{

}

QFuture<Result<WeatherData>> WeatherRepository::getDailyWeather(const std::string& city, const std::string& date) {
    // Проверяем кэш
    auto cachedWeek = cache_->getWeekWeather(city);
    if (cachedWeek.isSuccess()) {
        auto day = findDayInWeek(cachedWeek.value(), date);
        if (day.isSuccess()) {
            return makeReadyFuture(Result<WeatherData>::success(day.value()));
        }
    }

    // Нет в кэше → делаем запрос к API
    auto futureFromApi = api_->findWeatherDataByCity(city);

    auto* interface = new QFutureInterface<Result<WeatherData>>();
    interface->reportStarted();

    auto* watcher = new QFutureWatcher<Result<WeekWeatherData>>();
    watcher->setFuture(futureFromApi);

    QObject::connect(watcher, &QFutureWatcherBase::finished, this, [interface, watcher, this, city, date]() {
        const auto result = watcher->result();

        if (!result.isSuccess()) {
            interface->reportResult(Result<WeatherData>::failure(result.errorMessage()));
            interface->reportFinished();
            watcher->deleteLater();
            return;
        }

        const auto& week = result.value();
        cache_->addWeekWeather(city, week); // сохраняем в кэш

        auto day = findDayInWeek(week, date);
        if (day.isSuccess()) {
            interface->reportResult(Result<WeatherData>::success(day.value()));
        } else {
            interface->reportResult(Result<WeatherData>::failure("День не найден"));
        }

        interface->reportFinished();
        watcher->deleteLater();
    });

    return interface->future();
}

QFuture<Result<WeekWeatherData>> WeatherRepository::getWeeklyWeather(const std::string& city) {
    auto cached = cache_->getWeekWeather(city);
    if (cached.isSuccess()) {
        return makeReadyFuture(Result<WeekWeatherData>::success(cached.value()));
    }

    auto futureFromApi = api_->findWeatherDataByCity(city);

    auto* interface = new QFutureInterface<Result<WeekWeatherData>>();
    interface->reportStarted();

    auto* watcher = new QFutureWatcher<Result<WeekWeatherData>>();
    watcher->setFuture(futureFromApi);

    QObject::connect(watcher, &QFutureWatcherBase::finished, this, [interface, watcher, this, city]() {
        const auto result = watcher->result();
        if (result.isSuccess()) {
            cache_->addWeekWeather(city, result.value());
        }
        interface->reportResult(result);
        interface->reportFinished();
        watcher->deleteLater();
    });

    return interface->future();
}

Result<WeatherData> WeatherRepository::findDayInWeek(const WeekWeatherData &week, const std::string &targetDate)
{
    for (const auto& day : week.dailyWeather) {
        if (day.date == targetDate) {
            return Result<WeatherData>::success(day);
        }
    }
    return Result<WeatherData>::failure("Не нашлись данные о погоде о текущей дате");
}
