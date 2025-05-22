#ifndef GETWEEKLYWEATHERUSECASE_H
#define GETWEEKLYWEATHERUSECASE_H

#include <QDate>
#include <functional>
#include <memory>
#include <string>

#include "../entities/WeekWeatherData.h"
#include "../interfaces/weather/IWeatherRepository.h"
#include "../utils/Result.h"

class GetWeeklyWeatherUseCase
{
  public:
	explicit GetWeeklyWeatherUseCase(IWeatherRepository *weatherRepo);
	QFuture<Result<WeekWeatherData>> execute(const std::string &city);

  private:
	IWeatherRepository *weatherRepository_;
};

#endif // GETWEEKLYWEATHERUSECASE_H
