#ifndef APICONFIG_H
#define APICONFIG_H

#include <string>

class ApiConfig
{
  public:
	ApiConfig();
	ApiConfig(const std::string &urlFindCityByName,
	          const std::string &urlFindWeatherByCoordinates,
	          const std::string &key);

	const std::string &getUrlFindCityByName() const;
	const std::string &getUrlFindWeatherByCoordinates() const;
	const std::string &getKey() const;

	void setUrlFindCityByName(const std::string &url);
	void setUrlFindWeatherByCoordinates(const std::string &url);
	void setKey(const std::string &key);

  private:
	std::string urlFindCityByName_;
	std::string urlFindWeatherByCoordinates_;
	std::string key_;
};

#endif // APICONFIG_H
