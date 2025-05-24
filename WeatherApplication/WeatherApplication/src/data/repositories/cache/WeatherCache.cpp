#include "WeatherCache.h"

#include <QDebug>
#include <limits>
WeatherCache::WeatherCache(std::shared_ptr<IConfigProvider> config)
 : configProvider_(std::move(config))
{
}

Result<WeatherData> WeatherCache::getDayWeather(const std::string &city,
                                                const std::string &date)
{
	Result<WeatherData> result;
    if (!hasValidData(city)) {
		result = Result<WeatherData>::failure(
		    "Не нашлись данные о погоде в городе " + city);
    } else {
		const auto &days = cache_.at(city).data.getDailyWeather();
		int index = findDayIndex(days, date);
        if (index >= 0 && index < MAX_COUNT_DAYS) {
			result = Result<WeatherData>::success(days[index]);
        } else {
			result = Result<WeatherData>::failure(
			    "Не нашлись данные о погоде в городе " + city + " с датой " +
			    date);
		}
	}
	return result;
}

Result<WeekWeatherData> WeatherCache::getWeekWeather(const std::string &city)
{
	Result<WeekWeatherData> result;
    if (!hasValidData(city)) {
		result = Result<WeekWeatherData>::failure(
		    "Не нашлись данные о погоде в городе " + city);
    } else {
		result = Result<WeekWeatherData>::success(cache_.at(city).data);
	}
	return result;
}

void WeatherCache::addWeekWeather(const std::string &city,
                                  const WeekWeatherData &data)
{
    initConfig();
	clearExpired();
	size_t dataSize = calculateDataSize(data);
    if (currentCacheSize_ > std::numeric_limits<size_t>::max() - dataSize) {
		return;
	}
    while (currentCacheSize_ + dataSize > cacheConfig_->getMaxMemoryBytes()
           && !cache_.empty()) {
		removeOldestEntry();
	}
    if (currentCacheSize_ + dataSize <= cacheConfig_->getMaxMemoryBytes()) {
		cache_[city] = {data, std::chrono::system_clock::now()};
		currentCacheSize_ += dataSize;
	}
}

bool WeatherCache::hasValidData(const std::string &city)
{
	bool result = false;
	auto it = cache_.find(city);
    if (it != cache_.end()) {
		result = !isExpired(it->second);
	}
	return result;
}

bool WeatherCache::isExpired(const CacheEntry &entry) const
{
	bool result = false;
	auto now = std::chrono::system_clock::now();
	auto age =
	    std::chrono::duration_cast<std::chrono::seconds>(now - entry.timestamp)
	        .count();
    if (age > CACHE_EXPIRATION_SECONDS) {
		result = true;
	}
	return result;
}

int WeatherCache::findDayIndex(const std::vector<WeatherData> &days,
                               const std::string &date) const
{
	int result = -1;
    for (size_t i = 0; i < days.size(); ++i) {
        if (days[i].getDate() == date) {
			result = static_cast<int>(i);
			break;
		}
	}
	return result;
}

void WeatherCache::removeCity(const std::string &city)
{
	auto it = cache_.find(city);
    if (it != cache_.end()) {
		currentCacheSize_ -= calculateDataSize(it->second.data);
		cache_.erase(it);
	}
}

void WeatherCache::clearExpired()
{
    for (auto it = cache_.begin(); it != cache_.end();) {
        if (isExpired(it->second)) {
			currentCacheSize_ -= calculateDataSize(it->second.data);
			it = cache_.erase(it);
        } else {
			++it;
		}
	}
}

void WeatherCache::removeOldestEntry()
{
    if (cache_.empty()) {
		return;
	}
	auto oldestIt = cache_.begin();
    for (auto it = std::next(cache_.begin()); it != cache_.end(); ++it) {
        if (it->second.timestamp < oldestIt->second.timestamp) {
			oldestIt = it;
		}
	}
	cache_.erase(oldestIt);
}

void WeatherCache::initConfig()
{
    if (!cacheConfig_) {
        cacheConfig_ = std::make_shared<CacheConfig>();
        *cacheConfig_ = configProvider_->getCacheConfig();
    }
}

size_t WeatherCache::calculateDataSize(const WeekWeatherData &data) const
{
	size_t totalSize = 0;
    for (const auto &day : data.getDailyWeather()) {
		totalSize += bytesWeatherData(day);
	}
	totalSize += sizeof(data);
	return totalSize;
}

size_t WeatherCache::bytesWeatherData(const WeatherData &day) const
{
	size_t totalSize = 0;
	totalSize += sizeof(day.getLat());
	totalSize += sizeof(day.getLon());
	totalSize += sizeof(day.getTemp());
	totalSize += sizeof(day.getFeelsLike());
	totalSize += sizeof(day.getTempMax());
	totalSize += sizeof(day.getTempMin());
	totalSize += sizeof(day.getWindSpeed());
	totalSize += sizeof(day.getHumidity());
	totalSize += sizeof(day.getPressure());
	totalSize += day.getCity().size();
	totalSize += day.getDate().size();
	totalSize += day.getDescription().size();
	totalSize += day.getMessageError().size();
	return totalSize;
}
