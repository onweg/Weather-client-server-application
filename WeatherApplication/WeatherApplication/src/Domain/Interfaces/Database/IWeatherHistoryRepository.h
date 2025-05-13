#ifndef IWEATHERHISTORYREPOSITORY_H
#define IWEATHERHISTORYREPOSITORY_H

#include <vector>

#include "../../Entities/WeatherHistoryItem.h"

class IWeatherHistoryRepository {
 public:
  virtual ~IWeatherHistoryRepository() = default;
  virtual std::vector<WeatherHistoryItem> getAll() = 0;
  virtual void save(const std::string &city, const std::string &date) = 0;
};

#endif  // IWEATHERHISTORYREPOSITORY_H
