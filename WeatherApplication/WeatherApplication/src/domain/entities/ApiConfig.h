#ifndef APICONFIG_H
#define APICONFIG_H

#include <QString>
#include <QUrl>
#include <QUrlQuery>

class ApiConfig {
public:
    ApiConfig(const QString& baseUrl, const QString& apiKey)
        : baseUrl_(baseUrl), apiKey_(apiKey) {}

    QUrl buildFindCityByNameUrl(const QString& cityName) const {
        QUrl url(baseUrl_ + "/geo/1.0/direct");
        QUrlQuery query;
        query.addQueryItem("q", cityName);
        query.addQueryItem("limit", "5");
        query.addQueryItem("appid", apiKey_);
        url.setQuery(query);
        return url;
    }

    QUrl buildWeatherByCoordinatesUrl(double lat, double lon) const {
        QUrl url(baseUrl_ + "/data/2.5/forecast");
        QUrlQuery query;
        query.addQueryItem("lat", QString::number(lat));
        query.addQueryItem("lon", QString::number(lon));
        query.addQueryItem("units", "metric");
        query.addQueryItem("lang", "ru");
        query.addQueryItem("appid", apiKey_);
        url.setQuery(query);
        return url;
    }

private:
    QString baseUrl_;
    QString apiKey_;
};

#endif // APICONFIG_H
