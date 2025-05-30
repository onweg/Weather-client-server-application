#ifndef IAPIWEATHERSOURCE_H
#define IAPIWEATHERSOURCE_H

#include <QFuture>
#include <functional>
#include <string>

#include "../../entities/WeekWeatherData.h"
#include "../../utils/Result.h"

class IApiWeatherSource
{
  public:
	virtual ~IApiWeatherSource() = default;
	virtual QFuture<Result<WeekWeatherData>>
	findWeatherDataByCity(const std::string city) = 0;
};

#endif // IAPIWEATHERSOURCE_H
