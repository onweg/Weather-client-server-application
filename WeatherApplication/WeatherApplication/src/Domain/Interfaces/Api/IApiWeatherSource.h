#ifndef IAPIWEATHERSOURCE_H
#define IAPIWEATHERSOURCE_H

#include <string>
#include <functional>
#include <QFuture>
#include "../../Entities/WeekWeatherData.h"
#include "../../Utils/Result.h"

class IApiWeatherSource {
public:
    virtual ~IApiWeatherSource() = default;
    // принимаем примитивы возвращаем entiry
    virtual QFuture<Result<WeekWeatherData>> findWeatherDataByCity(const std::string city) = 0;
};

#endif // IAPIWEATHERSOURCE_H
