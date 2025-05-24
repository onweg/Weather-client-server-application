#ifndef APICONFIG_H
#define APICONFIG_H

#include <QString>
#include <QUrl>
#include <QUrlQuery>

class ApiConfig {
public:
    ApiConfig();
    ApiConfig(const QString& baseUrl, const QString& apiKey);
    QUrl buildFindCityByNameUrl(const QString& cityName) const;
    QUrl buildWeatherByCoordinatesUrl(double lat, double lon) const;

private:
    QString baseUrl_;
    QString apiKey_;
};

#endif // APICONFIG_H
