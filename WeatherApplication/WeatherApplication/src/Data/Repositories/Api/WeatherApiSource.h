#ifndef WEATHERAPISOURCE_H
#define WEATHERAPISOURCE_H

#include <QNetworkAccessManager>
#include <QObject>
#include <functional>
#include <memory>

#include "../../../Domain/Interfaces/Api/IApiWeatherSource.h"
#include "../../../Domain/Interfaces/Config/IConfigProvider.h"
#include "../../../Domain/Interfaces/SharedState/ISharedState.h"

class WeatherApiSource : public QObject, public IApiWeatherSource {
    Q_OBJECT
public:
    explicit WeatherApiSource(std::shared_ptr<IConfigProvider> config, QObject *parent = nullptr);

    void findWeatherDataByCity(const std::string city,
        std::function<void(Result<WeekWeatherData>)> callback) override;

private:
    std::shared_ptr<IConfigProvider> configProvider_;
    Result<ApiConfig> apiConfig_;
    QNetworkAccessManager *networkManager_;

    bool isApiConfigValid(std::string &errorMsg) const;
    QString buildCitySearchUrl(const std::string &city) const;
    QString buildWeatherUrl(double lat, double lon) const;

    Result<QPair<double, double>> parseCityCoordinates(const QByteArray &data) const;
    Result<WeekWeatherData> parseWeatherData(const QByteArray &data) const;

    void makeRequest(const QUrl &url,
        std::function<void(QByteArray, QString)> callback);
};

#endif // WEATHERAPISOURCE_H
