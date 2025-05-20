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
    // принимаем примитивы, преобразует в DTO, преобразует в JSON, отправляет на сервер JSON, принмает c сервера JSON, преобразует в DTO, преобразует в entity, возвращаем entiry
    QFuture<Result<WeekWeatherData>> findWeatherDataByCity(const std::string city) override;

private:
    Result<void> tryInitConfig();
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
    QString buildCityRequestUrl(const std::string& city) const;
    Result<std::pair<QString, QString>> parseCityCoordinatesJson(QNetworkReply* reply);
    Result<WeekWeatherData> parseWeatherJson(QNetworkReply* reply);
    QFuture<Result<WeekWeatherData>> finishWithImmediateError(
        QFutureInterface<Result<WeekWeatherData>>& futureInterface,
        const std::string& errorMessage);

    std::shared_ptr<IConfigProvider> configProvider_;
    std::shared_ptr<ApiConfig> apiConfig_;
    QNetworkAccessManager* networkManager_;
};

#endif // WEATHERAPISOURCE_H
