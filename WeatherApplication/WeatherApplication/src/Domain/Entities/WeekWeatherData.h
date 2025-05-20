#ifndef WEEKWEATHERDATA_H
#define WEEKWEATHERDATA_H

#include <string>
#include <vector>

#include "WeatherData.h"

class WeekWeatherData
{
private:
    std::string m_city;
    std::vector<WeatherData> m_dailyWeather;
    std::string m_messageError;

public:
    const std::string& getCity() const;
    void setCity(const std::string& city);

    const std::vector<WeatherData>& getDailyWeather() const;
    void setDailyWeather(const std::vector<WeatherData>& dailyWeather);

    const std::string& getMessageError() const;
    void setMessageError(const std::string& messageError);

    bool operator==(const WeekWeatherData& other) const;
    bool operator!=(const WeekWeatherData& other) const;
};

#endif // WEEKWEATHERDATA_H
