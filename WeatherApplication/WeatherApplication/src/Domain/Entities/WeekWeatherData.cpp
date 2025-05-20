#include "WeekWeatherData.h"

WeekWeatherData::WeekWeatherData()
    : m_city(""), m_messageError("")
{
}

WeekWeatherData::WeekWeatherData(const std::string& city,
                                 const std::vector<WeatherData>& dailyWeather,
                                 const std::string& messageError)
    : m_city(city), m_dailyWeather(dailyWeather), m_messageError(messageError)
{
}

const std::string& WeekWeatherData::getCity() const
{
    return m_city;
}

void WeekWeatherData::setCity(const std::string& city)
{
    m_city = city;
}

const std::vector<WeatherData>& WeekWeatherData::getDailyWeather() const
{
    return m_dailyWeather;
}

void WeekWeatherData::setDailyWeather(const std::vector<WeatherData>& dailyWeather)
{
    m_dailyWeather = dailyWeather;
}

const std::string& WeekWeatherData::getMessageError() const
{
    return m_messageError;
}

void WeekWeatherData::setMessageError(const std::string& messageError)
{
    m_messageError = messageError;
}

bool WeekWeatherData::operator==(const WeekWeatherData& other) const
{
    return m_city == other.m_city &&
           m_messageError == other.m_messageError &&
           m_dailyWeather.size() == other.m_dailyWeather.size() &&
           std::equal(m_dailyWeather.begin(), m_dailyWeather.end(), other.m_dailyWeather.begin());
}

bool WeekWeatherData::operator!=(const WeekWeatherData& other) const
{
    return !(*this == other);
}
