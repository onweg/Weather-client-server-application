#include "WeatherCache.h"

WeatherCache::WeatherCache() {}

Result<WeatherData> WeatherCache::getDayWeather(const std::string& city, const std::string& date) {
    if (!hasValidData(city)) {
        return Result<WeatherData>::failure("Не нашлись данные о погоде в городе " + city);
    }

    const auto& days = cache_.at(city).data.getDailyWeather();
    int index = findDayIndex(days, date);
    if (index >= 0 && index < MAX_COUNT_DAYS) {
        return Result<WeatherData>::success(days[index]);
    }

    return Result<WeatherData>::failure("Не нашлись данные о погоде в городе " + city + " с датой " + date);
}

Result<WeekWeatherData> WeatherCache::getWeekWeather(const std::string& city) {
    if (!hasValidData(city)) {
        return Result<WeekWeatherData>::failure("Не нашлись данные о погоде в городе " + city);
    }
    return Result<WeekWeatherData>::success(cache_.at(city).data);
}

void WeatherCache::addWeekWeather(const std::string& city, const WeekWeatherData& data) {
    cache_[city] = {data, std::chrono::system_clock::now()};
}

bool WeatherCache::hasValidData(const std::string& city) {
    auto it = cache_.find(city);
    if (it == cache_.end()) {
        return false;
    }
    return !isExpired(it->second);
}

bool WeatherCache::isExpired(const CacheEntry& entry) const {
    auto now = std::chrono::system_clock::now();
    auto age = std::chrono::duration_cast<std::chrono::seconds>(now - entry.timestamp).count();
    return age > CACHE_EXPIRATION_SECONDS;
}

int WeatherCache::findDayIndex(const std::vector<WeatherData>& days, const std::string& date) const {
    for (size_t i = 0; i < days.size(); ++i) {
        if (days[i].getDate() == date) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

void WeatherCache::removeCity(const std::string& city) {
    cache_.erase(city);
}

void WeatherCache::clearExpired() {
    for (auto it = cache_.begin(); it != cache_.end();) {
        if (isExpired(it->second)) {
            it = cache_.erase(it);
        } else {
            ++it;
        }
    }
}
