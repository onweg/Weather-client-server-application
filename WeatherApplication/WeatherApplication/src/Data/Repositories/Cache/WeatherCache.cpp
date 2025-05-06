#include "WeatherCache.h"

WeatherCache::WeatherCache() {}

Result<WeatherData> WeatherCache::getDayWeather(const std::string& city, const std::string& date) {
    auto it = cache_.find(city);
    if (it == cache_.end() || isExpired(it->second)) {
		return Result<WeatherData>::failure("Не нашлись данные о погоде в городе " + city);
	}

    const auto& days = it->second.data.dailyWeather;
    int index = findDayIndex(days, date);
    if (index >= 0) {
		return Result<WeatherData>::success(days[index]);
	}

    return Result<WeatherData>::failure("Не нашлись данные о погоде в городе " + city + " с датой " + date);
}

Result<WeekWeatherData> WeatherCache::getWeekWeather(const std::string& city) {
    auto it = cache_.find(city);
    if (it == cache_.end() || isExpired(it->second)) {
		return Result<WeekWeatherData>::failure("Не нашлись данные о погоде в городе " + city);
	}
    return Result<WeekWeatherData>::success(it->second.data);
}

void WeatherCache::addWeekWeather(const std::string& city, const WeekWeatherData& data) {
    cache_[city] = {data, std::chrono::system_clock::now()};
}

void WeatherCache::removeCity(const std::string& city) {
    cache_.erase(city);
}

void WeatherCache::clearExpired() {
    auto now = std::chrono::system_clock::now();
    for (auto it = cache_.begin(); it != cache_.end();) {
        if (isExpired(it->second)) {
            it = cache_.erase(it);
        } else {
            ++it;
        }
    }
}

bool WeatherCache::isExpired(const CacheEntry& entry) const {
    auto now = std::chrono::system_clock::now();
    auto age = std::chrono::duration_cast<std::chrono::seconds>(now - entry.timestamp).count();
    return age > CACHE_EXPIRATION_SECONDS;
}

int WeatherCache::findDayIndex(const std::vector<WeatherData>& days, const std::string& date) const {
    for (size_t i = 0; i < days.size(); ++i) {
        if (days[i].date == date) return static_cast<int>(i);
    }
    return -1;
}
