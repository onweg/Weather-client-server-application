#include "ApiConfig.h"

ApiConfig::ApiConfig()
 : urlFindCityByName_(""), urlFindWeatherByCoordinates_(""), key_("")
{
}

ApiConfig::ApiConfig(const std::string &urlFindCityByName,
                     const std::string &urlFindWeatherByCoordinates,
                     const std::string &key)
 : urlFindCityByName_(urlFindCityByName),
   urlFindWeatherByCoordinates_(urlFindWeatherByCoordinates), key_(key)
{
}

const std::string &ApiConfig::getUrlFindCityByName() const
{
	return urlFindCityByName_;
}

const std::string &ApiConfig::getUrlFindWeatherByCoordinates() const
{
	return urlFindWeatherByCoordinates_;
}

const std::string &ApiConfig::getKey() const
{
	return key_;
}

void ApiConfig::setUrlFindCityByName(const std::string &url)
{
	urlFindCityByName_ = url;
}

void ApiConfig::setUrlFindWeatherByCoordinates(const std::string &url)
{
	urlFindWeatherByCoordinates_ = url;
}

void ApiConfig::setKey(const std::string &key)
{
	key_ = key;
}
