#ifndef WEATHERAPISOURCE_H
#define WEATHERAPISOURCE_H

#include <QObject>
#include <QNetworkAccessManager>
#include <memory>
#include <functional>

#include "../../../Domain/Interfaces/Api/IApiWeatherSource.h"
#include "../../../Domain/Interfaces/Config/IConfigProvider.h"
#include "../../../Domain/Interfaces/SharedState/ISharedState.h"

class WeatherApiSource : public QObject, public IApiWeatherSource {
    Q_OBJECT
public:
    explicit WeatherApiSource(std::shared_ptr<IConfigProvider> config,
                              QObject* parent = nullptr);

    void findWeatherDataByCity(const std::string city,
                                                  std::function<void(Result<WeekWeatherData>)> callback) override;

private:
    std::shared_ptr<IConfigProvider> configProvider_;
    Result<ApiConfig> apiConfig_;
    QNetworkAccessManager* networkManager_;
};

#endif // WEATHERAPISOURCE_H
