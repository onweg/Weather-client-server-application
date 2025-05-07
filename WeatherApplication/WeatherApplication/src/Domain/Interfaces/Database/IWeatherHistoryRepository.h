#ifndef IWEATHERHISTORYREPOSITORY_H
#define IWEATHERHISTORYREPOSITORY_H

#include "../../Entities/WeatherHistoryItem.h"
#include <vector>

class IWeatherHistoryRepository {
public:
    virtual ~IWeatherHistoryRepository() = default;
    virtual std::vector<WeatherHistoryItem> getAll() = 0;
    virtual void save(const std::string &city, const std::string &date) = 0;
};

#endif // IWEATHERHISTORYREPOSITORY_H
