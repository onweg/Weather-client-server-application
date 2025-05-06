#ifndef IAPIWEATHERSOURCE_H
#define IAPIWEATHERSOURCE_H

#include <string>
#include <functional>
#include "../../Entities/WeekWeatherData.h"
#include "../../Utils/Result.h"

class IApiWeatherSource {
public:
    virtual ~IApiWeatherSource() = default;

    virtual void findWeatherDataByCity(const std::string city, std::function<void(Result<WeekWeatherData>)> callback) = 0;
};

#endif // IAPIWEATHERSOURCE_H
