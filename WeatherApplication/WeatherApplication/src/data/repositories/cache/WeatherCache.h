#ifndef WEATHERCACHE_H
#define WEATHERCACHE_H

#include <chrono>
#include <ctime>
#include <memory>
#include <unordered_map>

#include "../../../domain/interfaces/cache/IWeatherCacheSource.h"
#include "../../../domain/interfaces/config/IConfigProvider.h"

class WeatherCache : public IWeatherCacheSource
{
  public:
	WeatherCache(std::shared_ptr<IConfigProvider> config);
	Result<WeatherData> getDayWeather(const std::string &city,
	                                  const std::string &date) override;
	Result<WeekWeatherData> getWeekWeather(const std::string &city) override;
	void addWeekWeather(const std::string &city,
	                    const WeekWeatherData &data) override;

  private:
	std::shared_ptr<IConfigProvider> configProvider_;
	std::shared_ptr<CacheConfig> cacheConfig_;
	size_t currentCacheSize_ = 0;

	struct CacheEntry
	{
		WeekWeatherData data;
		std::chrono::system_clock::time_point timestamp;
	};

	static constexpr int CACHE_EXPIRATION_SECONDS = 3600;
	static constexpr int MAX_COUNT_DAYS = 5;
	std::unordered_map<std::string, CacheEntry> cache_;

	bool hasValidData(const std::string &city);
	bool isExpired(const CacheEntry &entry) const;
	int findDayIndex(const std::vector<WeatherData> &days,
	                 const std::string &date) const;
	void removeCity(const std::string &city);
	void clearExpired();
	void removeOldestEntry();
	void initConfig();
	size_t calculateDataSize(const WeekWeatherData &data) const;
	size_t bytesWeatherData(const WeatherData &day) const;
};

#endif // WEATHERCACHE_H
