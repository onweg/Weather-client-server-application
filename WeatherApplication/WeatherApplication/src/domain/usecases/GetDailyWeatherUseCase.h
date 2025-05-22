#ifndef GETDAILYWEATHERUSECASE_H
#define GETDAILYWEATHERUSECASE_H

#include <functional>
#include <memory>
#include <string>

#include "../entities/WeatherData.h"
#include "../interfaces/weather/IWeatherRepository.h"

class GetDailyWeatherUseCase
{
  public:
	explicit GetDailyWeatherUseCase(IWeatherRepository *weatherRepo);
	QFuture<Result<WeatherData>> execute(const std::string &city,
	                                     const std::string &date);

  private:
	IWeatherRepository *weatherRepository_;
};

#endif // GETDAILYWEATHERUSECASE_H
