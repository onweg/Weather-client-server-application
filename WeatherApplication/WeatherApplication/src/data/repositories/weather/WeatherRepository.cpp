#include "WeatherRepository.h"

#include <QDebug>
#include <QFutureInterface>
#include <QFutureWatcher>

#include "../../../domain/utils/MakeReadyFuture.h"

WeatherRepository::WeatherRepository(std::shared_ptr<IWeatherCacheSource> cache,
                                     IApiWeatherSource *api, QObject *parent)
 : QObject(parent), cache_(std::move(cache)), api_(api)
{
}

QFuture<Result<WeatherData>>
WeatherRepository::getDailyWeather(const std::string &city,
                                   const std::string &date)
{
    auto cachedResult = cache_->getWeekWeather(city);
    if (cachedResult.isSuccess()) {
        auto dayResult = findDayInWeek(cachedResult.value(), date);
        if (dayResult.isSuccess()) {
            return makeReadyFuture(Result<WeatherData>::success(dayResult.value()));
		}
	}
	return fetchAndProcessWeatherForDay(city, date);
}

QFuture<Result<WeekWeatherData>>
WeatherRepository::getWeeklyWeather(const std::string &city)
{
    auto cachedResult = cache_->getWeekWeather(city);
    if (cachedResult.isSuccess()) {
		return makeReadyFuture(
            Result<WeekWeatherData>::success(cachedResult.value()));
	}
	return fetchAndProcessWeatherForWeek(city);
}

Result<WeatherData>
WeatherRepository::findDayInWeek(const WeekWeatherData &week,
                                 const std::string &targetDate)
{
    for (const auto &day : week.getDailyWeather()) {
        if (day.getDate() == targetDate) {
			return Result<WeatherData>::success(day);
		}
	}
	return Result<WeatherData>::failure(
	    "Не нашлись данные о погоде о текущей дате");
}

QFuture<Result<WeatherData>>
WeatherRepository::fetchAndProcessWeatherForDay(const std::string &city,
                                                const std::string &date)
{
	QFutureInterface<Result<WeatherData>> *interface =
	    new QFutureInterface<Result<WeatherData>>();
	interface->reportStarted();
	QFutureWatcher<Result<WeekWeatherData>> *watcher =
	    new QFutureWatcher<Result<WeekWeatherData>>();
	watcher->setFuture(api_->findWeatherDataByCity(city));
	connect(watcher, &QFutureWatcherBase::finished, this,
	        [interface, watcher, this, city, date]()
	        { handleApiResultForDay(interface, watcher, city, date); });
	return interface->future();
}

void WeatherRepository::handleApiResultForDay(
    QFutureInterface<Result<WeatherData>> *interface,
    QFutureWatcher<Result<WeekWeatherData>> *watcher, const std::string &city,
    const std::string &date)
{
	Result<WeekWeatherData> result = watcher->result();
    if (!result.isSuccess()) {
		reportFailure(interface, result.errorMessage());
		cleanupAfter(interface, watcher);
		return;
	}
	const WeekWeatherData &week = result.value();
	cache_->addWeekWeather(city, week);
    Result<WeatherData> dayResult = findDayInWeek(week, date);
    if (dayResult.isSuccess()) {
        interface->reportResult(Result<WeatherData>::success(dayResult.value()));
    } else {
		interface->reportResult(Result<WeatherData>::failure("День не найден"));
	}
	cleanupAfter(interface, watcher);
}

QFuture<Result<WeekWeatherData>>
WeatherRepository::fetchAndProcessWeatherForWeek(const std::string &city)
{
	QFutureInterface<Result<WeekWeatherData>> *interface =
	    new QFutureInterface<Result<WeekWeatherData>>();
	interface->reportStarted();
	QFutureWatcher<Result<WeekWeatherData>> *watcher =
	    new QFutureWatcher<Result<WeekWeatherData>>();
	watcher->setFuture(api_->findWeatherDataByCity(city));
	connect(watcher, &QFutureWatcherBase::finished, this,
	        [interface, watcher, this, city]()
	        { handleApiResultForWeek(interface, watcher, city); });
	return interface->future();
}

void WeatherRepository::handleApiResultForWeek(
    QFutureInterface<Result<WeekWeatherData>> *interface,
    QFutureWatcher<Result<WeekWeatherData>> *watcher, const std::string &city)
{
	Result<WeekWeatherData> result = watcher->result();
    if (result.isSuccess()) {
		cache_->addWeekWeather(city, result.value());
	}
	interface->reportResult(result);
	interface->reportFinished();
	cleanupAfter(interface, watcher);
}

void WeatherRepository::cleanupAfter(QFutureInterfaceBase *interface,
                                     QObject *watcher)
{
	interface->reportFinished();
	watcher->deleteLater();
}

void WeatherRepository::reportFailure(
    QFutureInterface<Result<WeatherData>> *interface,
    const std::string &message)
{
	interface->reportResult(Result<WeatherData>::failure(message));
}
