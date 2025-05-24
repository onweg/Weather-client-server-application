#include "ApiConfig.h"

ApiConfig::ApiConfig() : m_baseUrl(""), m_apiKey("") {}

ApiConfig::ApiConfig(const QString &baseUrl, const QString &apiKey)
 : m_baseUrl(baseUrl), m_apiKey(apiKey)
{
}

QUrl ApiConfig::buildFindCityByNameUrl(const QString &cityName) const
{
	QUrl url(m_baseUrl + "/geo/1.0/direct");
	QUrlQuery query;
	query.addQueryItem("q", cityName);
	query.addQueryItem("limit", "5");
	query.addQueryItem("appid", m_apiKey);
	url.setQuery(query);
	return url;
}

QUrl ApiConfig::buildWeatherByCoordinatesUrl(double lat, double lon) const
{
	QUrl url(m_baseUrl + "/data/2.5/forecast");
	QUrlQuery query;
	query.addQueryItem("lat", QString::number(lat));
	query.addQueryItem("lon", QString::number(lon));
	query.addQueryItem("units", "metric");
	query.addQueryItem("lang", "ru");
	query.addQueryItem("appid", m_apiKey);
	url.setQuery(query);
	return url;
}
