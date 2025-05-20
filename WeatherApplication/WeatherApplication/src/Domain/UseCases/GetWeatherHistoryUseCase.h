#ifndef GETWEATHERHISTORYUSECASE_H
#define GETWEATHERHISTORYUSECASE_H

#include "../Interfaces/Database/IWeatherHistoryRepository.h"
#include <memory>

class GetWeatherHistoryUseCase
{
public:
    explicit GetWeatherHistoryUseCase(std::shared_ptr<IWeatherHistoryRepository> repository);
    // принимаем entity возвращаем entiry
    std::vector<WeatherHistoryItem> execute();

private:
    std::shared_ptr<IWeatherHistoryRepository> repository_;
};

#endif // GETWEATHERHISTORYUSECASE_H
