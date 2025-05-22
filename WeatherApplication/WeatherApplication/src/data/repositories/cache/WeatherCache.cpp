#include "WeatherCache.h"

WeatherCache::WeatherCache() {}

Result<WeatherData> WeatherCache::getDayWeather(const std::string &city,
                                                const std::string &date)
{
    Result<WeatherData> result;
    if (!hasValidData(city))
    {
        result = Result<WeatherData>::failure(
            "Не нашлись данные о погоде в городе " + city);
    }
    else
    {
        const auto &days = cache_.at(city).data.getDailyWeather();
        int index = findDayIndex(days, date);
        if (index >= 0 && index < MAX_COUNT_DAYS)
        {
            result = Result<WeatherData>::success(days[index]);
        }
        else
        {
            result = Result<WeatherData>::failure("Не нашлись данные о погоде в городе " +
                                                  city + " с датой " + date);
        }
    }
    return result;
}

Result<WeekWeatherData> WeatherCache::getWeekWeather(const std::string &city)
{
    Result<WeekWeatherData> result;
    if (!hasValidData(city))
    {
        result = Result<WeekWeatherData>::failure(
            "Не нашлись данные о погоде в городе " + city);
    }
    else
    {
        result = Result<WeekWeatherData>::success(cache_.at(city).data);
    }
    return result;
}

void WeatherCache::addWeekWeather(const std::string &city,
                                  const WeekWeatherData &data)
{
    clearExpired();
    if (cache_.size() >= MAX_CACHE_SIZE)
    {
        removeOldestEntry();
    }
    cache_[city] = {data, std::chrono::system_clock::now()};
}

bool WeatherCache::hasValidData(const std::string &city)
{
    bool result = false;
    auto it = cache_.find(city);
    if (it != cache_.end())
    {
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
    if (age > CACHE_EXPIRATION_SECONDS)
    {
        result = true;
    }
    return result;
}

int WeatherCache::findDayIndex(const std::vector<WeatherData> &days,
                               const std::string &date) const
{
    int result = -1;
    for (size_t i = 0; i < days.size(); ++i)
    {
        if (days[i].getDate() == date)
        {
            result = static_cast<int>(i);
            break;
        }
    }
    return result;
}

void WeatherCache::removeCity(const std::string &city)
{
    cache_.erase(city);
}

void WeatherCache::clearExpired()
{
    for (auto it = cache_.begin(); it != cache_.end();)
    {
        if (isExpired(it->second))
        {
            it = cache_.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void WeatherCache::removeOldestEntry()
{
    if (cache_.empty())
    {
        return;
    }
    auto oldestIt = cache_.begin();
    for (auto it = std::next(cache_.begin()); it != cache_.end(); ++it)
    {
        if (it->second.timestamp < oldestIt->second.timestamp)
        {
            oldestIt = it;
        }
    }
    cache_.erase(oldestIt);
}
