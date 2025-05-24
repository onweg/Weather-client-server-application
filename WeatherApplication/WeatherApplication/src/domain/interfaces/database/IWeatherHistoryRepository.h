#ifndef IWEATHERHISTORYREPOSITORY_H
#define IWEATHERHISTORYREPOSITORY_H

#include <memory>
#include <vector>

#include "../../entities/WeatherHistoryItem.h"

class IWeatherHistoryRepository
{
  public:
	virtual ~IWeatherHistoryRepository() = default;
	virtual void save(const std::string &city, const std::string &date) = 0;
	virtual std::vector<WeatherHistoryItem> getAll() = 0;
};

#endif // IWEATHERHISTORYREPOSITORY_H
