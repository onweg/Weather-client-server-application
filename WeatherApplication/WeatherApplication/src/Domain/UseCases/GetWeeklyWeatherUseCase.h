#ifndef GETWEEKLYWEATHERUSECASE_H
#define GETWEEKLYWEATHERUSECASE_H

#include <string>
#include <QDate>
#include <functional>
#include <memory>
#include "../Entities/WeekWeatherData.h"
#include "../Utils/Result.h"
#include "../Interfaces/Weather/IWeatherRepository.h"

class GetWeeklyWeatherUseCase {
public:
    explicit GetWeeklyWeatherUseCase(IWeatherRepository* weatherRepo);

    QFuture<Result<WeekWeatherData>> execute(const std::string& city);

private:
    IWeatherRepository* weatherRepository_;
};

#endif // GETWEEKLYWEATHERUSECASE_H
