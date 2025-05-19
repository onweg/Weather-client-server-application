#include "WeatherApiSource.h"
#include "../../../Utils/WeatherJsonConverter.h"

#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>
#include <QFutureInterface>

WeatherApiSource::WeatherApiSource(std::shared_ptr<IConfigProvider> config, QObject *parent)
    : QObject(parent), configProvider_(std::move(config))
{
    networkManager_ = new QNetworkAccessManager(this);
}

QFuture<Result<WeekWeatherData>> WeatherApiSource::findWeatherDataByCity(const std::string city) {
    QFutureInterface<Result<WeekWeatherData>> futureInterface;
    futureInterface.reportStarted();

    try {
        initConfig();
    } catch (const std::exception& e) {
        futureInterface.reportResult(Result<WeekWeatherData>::failure(e.what()));
        futureInterface.reportFinished();
        return futureInterface.future();
    }

    QString cityName = QString::fromStdString(city);
    QString url = QString::fromStdString(apiConfig_->urlFindCityByName).arg(cityName, QString::fromStdString(apiConfig_->key));
    QNetworkRequest request((QUrl(url)));
    QNetworkReply* reply = networkManager_->get(request);

    connect(reply, &QNetworkReply::finished, this, [this, reply, cityName, futureInterface]() mutable {
        handleCityCoordinatesReply(reply, futureInterface);
    });

    return futureInterface.future();
}

void WeatherApiSource::handleCityCoordinatesReply(QNetworkReply* reply,
                                                  QFutureInterface<Result<WeekWeatherData>>& futureInterface) {
    if (reply->error() != QNetworkReply::NoError) {
        finishWithError(futureInterface, reply->errorString().toStdString(), reply);
        return;
    }

    QByteArray responseData = reply->readAll();
    QJsonParseError error;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData, &error);
    if (error.error != QJsonParseError::NoError  || !jsonDocument.isArray() || jsonDocument.array().isEmpty()) {
        finishWithError(futureInterface, "Ошибка при получении координат города", reply);
        return;
    }

    QJsonObject cityData = jsonDocument.array().at(0).toObject();
    QString lat = QString::number(cityData["lat"].toDouble());
    QString lon = QString::number(cityData["lon"].toDouble());

    fetchWeatherByCoordinates(lat, lon, futureInterface);
    reply->deleteLater();
}

void WeatherApiSource::fetchWeatherByCoordinates(const QString& lat, const QString& lon,
                                                 QFutureInterface<Result<WeekWeatherData>>& futureInterface) {
    QString weatherUrl = QString::fromStdString(apiConfig_->urlFindWeatherByCoordinates)
                             .arg(lat, lon, QString::fromStdString(apiConfig_->key));

    QNetworkRequest request((QUrl(weatherUrl)));
    QNetworkReply* reply = networkManager_->get(request);

    connect(reply, &QNetworkReply::finished, this, [this, reply, futureInterface]() mutable {
        handleWeatherReply(reply, futureInterface);
    });
}

void WeatherApiSource::handleWeatherReply(QNetworkReply* reply,
                                          QFutureInterface<Result<WeekWeatherData>>& futureInterface) {
    if (reply->error() != QNetworkReply::NoError) {
        finishWithError(futureInterface, reply->errorString().toStdString(), reply);
        return;
    }

    QByteArray data = reply->readAll();
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(data, &error);
    if (error.error != QJsonParseError::NoError || !doc.isObject()) {
        finishWithError(futureInterface, "Ошибка парсинга JSON с погодой", reply);
        return;
    }

    WeekWeatherData weatherData = WeatherJsonConverter::parseWeekWeather(doc.object());
    if (!weatherData.messageError.empty()) {
        finishWithError(futureInterface, weatherData.messageError, reply);
        return;
    }

    futureInterface.reportResult(Result<WeekWeatherData>::success(weatherData));
    futureInterface.reportFinished();
    reply->deleteLater();
}

void WeatherApiSource::finishWithError(QFutureInterface<Result<WeekWeatherData>>& futureInterface,
                                       const std::string& errorMessage, QNetworkReply* reply) {
    futureInterface.reportResult(Result<WeekWeatherData>::failure(errorMessage));
    futureInterface.reportFinished();
    if (reply) reply->deleteLater();
}

void WeatherApiSource::initConfig() {
    if (!apiConfig_) {
        auto result = configProvider_->getApiConfig();
        if (!result.isSuccess()) {
            throw std::runtime_error(result.errorMessage());
        }
        apiConfig_ = std::make_shared<ApiConfig>(result.value());
    }
}

