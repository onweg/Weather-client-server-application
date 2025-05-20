#ifndef SAVEWEATHERHISTORYUSECASE_H
#define SAVEWEATHERHISTORYUSECASE_H

#include "../Interfaces/Database/IWeatherHistoryRepository.h"
#include <memory>

class SaveWeatherHistoryUseCase {
public:
    explicit SaveWeatherHistoryUseCase(std::shared_ptr<IWeatherHistoryRepository> repository);
    // принимаем entity возвращаем entiry
    void execute(const std::string &city, const std::string &date);

private:
    std::shared_ptr<IWeatherHistoryRepository> repository_;
};

#endif // SAVEWEATHERHISTORYUSECASE_H
