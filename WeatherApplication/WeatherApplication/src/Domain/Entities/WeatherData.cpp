#include "WeatherData.h"

WeatherData::WeatherData()
    : m_lat(0.0),
      m_lon(0.0),
      m_city("..."),
      m_description("..."),
      m_temp(0.0),
      m_feels_like(0.0),
      m_temp_max(0.0),
      m_temp_min(0.0),
      m_wind_speed(0.0),
      m_humidity(0),
      m_pressure(0)
{
}

WeatherData::WeatherData(double lat,
                         double lon,
                         const std::string& city,
                         const std::string& date,
                         const std::string& description,
                         double temp,
                         double feels_like,
                         double temp_max,
                         double temp_min,
                         double wind_speed,
                         int humidity,
                         int pressure,
                         const std::string& messageError)
    : m_lat(lat),
      m_lon(lon),
      m_city(city),
      m_date(date),
      m_description(description),
      m_temp(temp),
      m_feels_like(feels_like),
      m_temp_max(temp_max),
      m_temp_min(temp_min),
      m_wind_speed(wind_speed),
      m_humidity(humidity),
      m_pressure(pressure),
      m_messageError(messageError)
{
}

double WeatherData::getLat() const
{
    return m_lat;
}

void WeatherData::setLat(double lat)
{
    m_lat = lat;
}

double WeatherData::getLon() const
{
    return m_lon;
}

void WeatherData::setLon(double lon)
{
    m_lon = lon;
}

const std::string& WeatherData::getCity() const
{
    return m_city;
}

void WeatherData::setCity(const std::string& city)
{
    m_city = city;
}

const std::string& WeatherData::getDate() const
{
    return m_date;
}

void WeatherData::setDate(const std::string& date)
{
    m_date = date;
}

const std::string& WeatherData::getDescription() const
{
    return m_description;
}

void WeatherData::setDescription(const std::string& description)
{
    m_description = description;
}

double WeatherData::getTemp() const
{
    return m_temp;
}

void WeatherData::setTemp(double temp)
{
    m_temp = temp;
}

double WeatherData::getFeelsLike() const
{
    return m_feels_like;
}

void WeatherData::setFeelsLike(double feels_like)
{
    m_feels_like = feels_like;
}

double WeatherData::getTempMax() const
{
    return m_temp_max;
}

void WeatherData::setTempMax(double temp_max)
{
    m_temp_max = temp_max;
}

double WeatherData::getTempMin() const
{
    return m_temp_min;
}

void WeatherData::setTempMin(double temp_min)
{
    m_temp_min = temp_min;
}

double WeatherData::getWindSpeed() const
{
    return m_wind_speed;
}

void WeatherData::setWindSpeed(double wind_speed)
{
    m_wind_speed = wind_speed;
}

int WeatherData::getHumidity() const
{
    return m_humidity;
}

void WeatherData::setHumidity(int humidity)
{
    m_humidity = humidity;
}

int WeatherData::getPressure() const
{
    return m_pressure;
}

void WeatherData::setPressure(int pressure)
{
    m_pressure = pressure;
}

const std::string& WeatherData::getMessageError() const
{
    return m_messageError;
}

void WeatherData::setMessageError(const std::string& messageError)
{
    m_messageError = messageError;
}

bool WeatherData::operator==(const WeatherData& other) const
{
    return m_city == other.m_city &&
           m_date == other.m_date &&
           m_description == other.m_description &&
           areAlmostEqual(m_lat, other.m_lat) &&
           areAlmostEqual(m_lon, other.m_lon) &&
           areAlmostEqual(m_temp, other.m_temp) &&
           areAlmostEqual(m_feels_like, other.m_feels_like) &&
           areAlmostEqual(m_temp_max, other.m_temp_max) &&
           areAlmostEqual(m_temp_min, other.m_temp_min) &&
           areAlmostEqual(m_wind_speed, other.m_wind_speed) &&
           m_humidity == other.m_humidity &&
           m_pressure == other.m_pressure;
}

bool WeatherData::operator!=(const WeatherData& other) const
{
    return !(*this == other);
}
