#ifndef GETWEEKLYWEATHERUSECASE_H
#define GETWEEKLYWEATHERUSECASE_H

#include <QDate>
#include <functional>
#include <memory>
#include <string>

#include "../Entities/WeekWeatherData.h"
#include "../Interfaces/Weather/IWeatherRepository.h"
#include "../Utils/Result.h"

class GetWeeklyWeatherUseCase
{
  public:
	explicit GetWeeklyWeatherUseCase(IWeatherRepository *weatherRepo);
	QFuture<Result<WeekWeatherData>> execute(const std::string &city);

  private:
	IWeatherRepository *weatherRepository_;
};

#endif // GETWEEKLYWEATHERUSECASE_H
