#ifndef WEATHERAPISOURCE_H
#define WEATHERAPISOURCE_H

#include <QObject>
#include <QNetworkAccessManager>
#include <memory>
#include <functional>
#include <QFutureInterface>

#include "../../../Domain/Interfaces/Api/IApiWeatherSource.h"
#include "../../../Domain/Interfaces/Config/IConfigProvider.h"
#include "../../../Domain/Interfaces/SharedState/ISharedState.h"

class WeatherApiSource : public QObject, public IApiWeatherSource {
    Q_OBJECT
public:
    explicit WeatherApiSource(std::shared_ptr<IConfigProvider> config,
                              QObject* parent = nullptr);

    QFuture<Result<WeekWeatherData>> findWeatherDataByCity(const std::string city) override;

private:
    void initConfig();
    void handleCityCoordinatesReply(QNetworkReply* reply,
                                    QFutureInterface<Result<WeekWeatherData>>& futureInterface);
    void fetchWeatherByCoordinates(const QString& lat,
                                   const QString& lon,
                                   QFutureInterface<Result<WeekWeatherData>>& futureInterface);
    void handleWeatherReply(QNetworkReply* reply,
                            QFutureInterface<Result<WeekWeatherData>>& futureInterface);
    void finishWithError(QFutureInterface<Result<WeekWeatherData>>& futureInterface,
                         const std::string& errorMessage,
                         QNetworkReply* reply);

    std::shared_ptr<IConfigProvider> configProvider_;
    std::shared_ptr<ApiConfig> apiConfig_;
    QNetworkAccessManager* networkManager_;
};

#endif // WEATHERAPISOURCE_H
