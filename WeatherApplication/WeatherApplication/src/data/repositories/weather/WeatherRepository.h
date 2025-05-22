#ifndef WEATHERREPOSITORY_H
#define WEATHERREPOSITORY_H

#include <memory>

#include "../../../domain/interfaces/api/IApiWeatherSource.h"
#include "../../../domain/interfaces/cache/IWeatherCacheSource.h"
#include "../../../domain/interfaces/weather/IWeatherRepository.h"

class WeatherRepository : public QObject, public IWeatherRepository
{
	Q_OBJECT
  public:
	explicit WeatherRepository(std::shared_ptr<IWeatherCacheSource> cache,
	                           IApiWeatherSource *api,
	                           QObject *parent = nullptr);
	QFuture<Result<WeatherData>>
	getDailyWeather(const std::string &city, const std::string &date) override;
	QFuture<Result<WeekWeatherData>>
	getWeeklyWeather(const std::string &city) override;

  private:
	std::shared_ptr<IWeatherCacheSource> cache_;
	IApiWeatherSource *api_;

	Result<WeatherData> findDayInWeek(const WeekWeatherData &week,
	                                  const std::string &targetDate);
	QFuture<Result<WeatherData>>
	fetchAndProcessWeatherForDay(const std::string &city,
	                             const std::string &date);
	void handleApiResultForDay(QFutureInterface<Result<WeatherData>> *interface,
	                           QFutureWatcher<Result<WeekWeatherData>> *watcher,
	                           const std::string &city,
	                           const std::string &date);
	QFuture<Result<WeekWeatherData>>
	fetchAndProcessWeatherForWeek(const std::string &city);
	void
	handleApiResultForWeek(QFutureInterface<Result<WeekWeatherData>> *interface,
	                       QFutureWatcher<Result<WeekWeatherData>> *watcher,
	                       const std::string &city);
	void cleanupAfter(QFutureInterfaceBase *interface, QObject *watcher);
	void reportFailure(QFutureInterface<Result<WeatherData>> *interface,
	                   const std::string &message);
};

#endif // WEATHERREPOSITORY_H
