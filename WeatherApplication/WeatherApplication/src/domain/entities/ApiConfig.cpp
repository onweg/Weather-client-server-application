#include "ApiConfig.h"

ApiConfig::ApiConfig()
 : m_urlFindCityByName(""), m_urlFindWeatherByCoordinates(""), m_key("")
{
}

ApiConfig::ApiConfig(const std::string &urlFindCityByName,
                     const std::string &urlFindWeatherByCoordinates,
                     const std::string &key)
 : m_urlFindCityByName(urlFindCityByName),
   m_urlFindWeatherByCoordinates(urlFindWeatherByCoordinates), m_key(key)
{
}

const std::string &ApiConfig::getUrlFindCityByName() const
{
    return m_urlFindCityByName;
}

const std::string &ApiConfig::getUrlFindWeatherByCoordinates() const
{
    return m_urlFindWeatherByCoordinates;
}

const std::string &ApiConfig::getKey() const
{
    return m_key;
}

void ApiConfig::setUrlFindCityByName(const std::string &url)
{
    m_urlFindCityByName = url;
}

void ApiConfig::setUrlFindWeatherByCoordinates(const std::string &url)
{
    m_urlFindWeatherByCoordinates = url;
}

void ApiConfig::setKey(const std::string &key)
{
    m_key = key;
}
