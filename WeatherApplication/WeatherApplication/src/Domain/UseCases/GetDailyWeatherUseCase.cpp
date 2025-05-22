#include "GetDailyWeatherUseCase.h"

GetDailyWeatherUseCase::GetDailyWeatherUseCase(IWeatherRepository *weatherRepo)
 : weatherRepository_(weatherRepo)
{
}

QFuture<Result<WeatherData>>
GetDailyWeatherUseCase::execute(const std::string &city,
                                const std::string &date)
{
	return weatherRepository_->getDailyWeather(city, date);
}
