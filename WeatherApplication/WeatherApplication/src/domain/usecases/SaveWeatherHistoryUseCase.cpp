#include "SaveWeatherHistoryUseCase.h"

SaveWeatherHistoryUseCase::SaveWeatherHistoryUseCase(
    std::shared_ptr<IWeatherHistoryRepository> repository)
 : repository_(std::move(repository))
{
}

void SaveWeatherHistoryUseCase::execute(const std::string &city,
                                        const std::string &date)
{
	repository_->save(city, date);
}
