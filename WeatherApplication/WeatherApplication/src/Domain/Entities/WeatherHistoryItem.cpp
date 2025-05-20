#include "WeatherHistoryItem.h"

int WeatherHistoryItem::getId() const
{
    return m_id;
}

void WeatherHistoryItem::setId(int id)
{
    m_id = id;
}

const std::string& WeatherHistoryItem::getUsername() const
{
    return m_username;
}

void WeatherHistoryItem::setUsername(const std::string& username)
{
    m_username = username;
}

const std::chrono::system_clock::time_point& WeatherHistoryItem::getTimestamp() const
{
    return m_timestamp;
}

void WeatherHistoryItem::setTimestamp(const std::chrono::system_clock::time_point& timestamp)
{
    m_timestamp = timestamp;
}

const std::string& WeatherHistoryItem::getCity() const
{
    return m_city;
}

void WeatherHistoryItem::setCity(const std::string& city)
{
    m_city = city;
}

const std::string& WeatherHistoryItem::getDate() const
{
    return m_date;
}

void WeatherHistoryItem::setDate(const std::string& date)
{
    m_date = date;
}
