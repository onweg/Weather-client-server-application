#include "GetWeeklyWeatherUseCase.h"

GetWeeklyWeatherUseCase::GetWeeklyWeatherUseCase(IWeatherRepository *weatherRepo)
    :weatherRepository_(weatherRepo)
{

}

QFuture<Result<WeekWeatherData> > GetWeeklyWeatherUseCase::execute(const std::string &city)
{
    return weatherRepository_->getWeeklyWeather(city);
}

