#ifndef WEATHERAPISOURCE_H
#define WEATHERAPISOURCE_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>
#include <QString>
#include <QDebug>

#include "IApiWeatherSource.h"
#include "../../Models/ApiConfig.h"
#include "../../Utils/Result.h"
#include "../../Entities/WeatherData.h"
#include "../../Entities/WeekWeatherData.h"

class WeatherApiSource : public QObject, public IApiWeatherSource {
    Q_OBJECT
public:
    explicit WeatherApiSource(QObject* parent = nullptr);

    void findWeatherByCity(const std::string city, const std::string date,
                           std::function<void(Result<WeatherData>)> callback) override;

    void findWeekWeatherByCity(const std::string city,
                               std::function<void(Result<WeekWeatherData>)> callback) override;

    void setConfig(const ApiConfig& config);

private slots:
    void onCityFound();
    void onWeatherReceived();

private:
    QNetworkAccessManager* manager_;
    ApiConfig apiConfig_;

    QNetworkReply* replyCity_ = nullptr;
    QNetworkReply* replyWeather_ = nullptr;

    std::function<void(Result<WeatherData>)> dayCallback_;
    std::function<void(Result<WeekWeatherData>)> weekCallback_;

    std::string requestedDate_;
    std::string requestedCity_;

    void requestWeatherByCoords(const QString& lat, const QString& lon);
    Result<WeatherData> parseDayWeather(const QJsonObject& json, const std::string& date);
    Result<WeekWeatherData> parseWeekWeather(const QJsonObject& json);
};

#endif // WEATHERAPISOURCE_H
