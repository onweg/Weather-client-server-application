#ifndef GETWEATHERHISTORYUSECASE_H
#define GETWEATHERHISTORYUSECASE_H

#include <memory>

#include "../interfaces/database/IWeatherHistoryRepository.h"

class GetWeatherHistoryUseCase
{
  public:
	explicit GetWeatherHistoryUseCase(
	    std::shared_ptr<IWeatherHistoryRepository> repository);
	std::vector<WeatherHistoryItem> execute();

  private:
	std::shared_ptr<IWeatherHistoryRepository> repository_;
};

#endif // GETWEATHERHISTORYUSECASE_H
