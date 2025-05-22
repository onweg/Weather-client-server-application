#include "GetWeatherHistoryUseCase.h"

GetWeatherHistoryUseCase::GetWeatherHistoryUseCase(
    std::shared_ptr<IWeatherHistoryRepository> repository)
 : repository_(std::move(repository))
{
}

std::vector<WeatherHistoryItem> GetWeatherHistoryUseCase::execute()
{
	return repository_->getAll();
}
