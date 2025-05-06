#ifndef WEATHERCACHE_H
#define WEATHERCACHE_H

#include <unordered_map>
#include <chrono>
#include <ctime>
#include <../../../Domain/Utils/Result>
#include "IWeatherDayCacheDataSource.h"
#include "IWeatherWeekCacheDataSource.h"

class WeatherCache : public IWeatherDayCacheDataSource, public IWeatherWeekCacheDataSource {
public:
    WeatherCache();

    Result<WeatherData> getDayWeather(const std::string& city, const std::string& date) override;
    Result<WeekWeatherData> getWeekWeather(const std::string& city) override;

    void addWeekWeather(const std::string& city, const WeekWeatherData& data);
    void removeCity(const std::string& city);
    void clearExpired();

private:
    struct CacheEntry {
        WeekWeatherData data;
        std::chrono::system_clock::time_point timestamp;
    };

    static constexpr int CACHE_EXPIRATION_SECONDS = 3600;
    std::unordered_map<std::string, CacheEntry> cache_;

    bool isExpired(const CacheEntry& entry) const;
    int findDayIndex(const std::vector<WeatherData>& days, const std::string& date) const;
};

#endif // WEATHERCACHE_H