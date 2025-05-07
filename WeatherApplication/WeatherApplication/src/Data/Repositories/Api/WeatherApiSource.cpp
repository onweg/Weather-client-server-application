#include "WeatherApiSource.h"
#include "../../../Utils/WeatherJsonConverter.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>
#include <QString>
#include <QDebug>

WeatherApiSource::WeatherApiSource(std::shared_ptr<IConfigProvider> config,
                                   QObject *parent)
    : QObject(parent), configProvider_(std::move(config)) {
    if (configProvider_) {
        apiConfig_ = configProvider_->getApiConfig();
    } else {
        apiConfig_ = Result<ApiConfig>::failure("Не удалось получить конфигурацию API");
        qWarning() << "Не удалось получить IConfigProvider";
    }
    networkManager_ = new QNetworkAccessManager(this);
}

void WeatherApiSource::findWeatherDataByCity(const std::string city,
                                                                 std::function<void(Result<WeekWeatherData>)> callback) {
    Result<WeekWeatherData> result;
    if (!apiConfig_.isSuccess()) {
        callback(Result<WeekWeatherData>::failure("Конфигурация API недоступна"));
        return;
    }

    QString cityName = QString::fromStdString(city);
    QString urlTemplate = QString::fromStdString(apiConfig_.value().urlFindCityByName);
    QString url = urlTemplate.arg(cityName, QString::fromStdString(apiConfig_.value().key));

    QUrl qurl(url);
    QNetworkRequest request(qurl);
    QNetworkReply* reply = networkManager_->get(request);

    connect(reply, &QNetworkReply::finished, this, [this, reply, callback, city]() {
        if (reply->error() != QNetworkReply::NoError) {
            callback(Result<WeekWeatherData>::failure(reply->errorString().toStdString()));
            reply->deleteLater();
            return;
        }

        QByteArray responseData = reply->readAll();
        QJsonParseError error;
        QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData, &error);
        if (error.error != QJsonParseError::NoError) {
            callback(Result<WeekWeatherData>::failure("Ошибка парсинга JSON: " + error.errorString().toStdString()));
            reply->deleteLater();
            return;
        }

        if (!jsonDocument.isArray()) {
            callback(Result<WeekWeatherData>::failure("Ожидался массив JSON"));
            reply->deleteLater();
            return;
        }

        QJsonArray jsonArray = jsonDocument.array();
        if (jsonArray.isEmpty()) {
            callback(Result<WeekWeatherData>::failure("Город не найден"));
            reply->deleteLater();
            return;
        }

        QJsonObject cityData = jsonArray[0].toObject();
        QString lat = QString::number(cityData["lat"].toDouble());
        QString lon = QString::number(cityData["lon"].toDouble());

        QString weatherTemplate = QString::fromStdString(apiConfig_.value().urlFindWeatherByCoordinates);
        QString weatherUrl = weatherTemplate.arg(lat, lon, QString::fromStdString(apiConfig_.value().key));

        QUrl weatherQurl(weatherUrl);
        QNetworkRequest weatherRequest(weatherQurl);
        QNetworkReply* weatherReply = networkManager_->get(weatherRequest);

        connect(weatherReply, &QNetworkReply::finished, this, [weatherReply, callback]() {
            if (weatherReply->error() != QNetworkReply::NoError) {
                callback(Result<WeekWeatherData>::failure(weatherReply->errorString().toStdString()));
                weatherReply->deleteLater();
                return;
            }

            QByteArray weatherData = weatherReply->readAll();
            QJsonParseError error;
            QJsonDocument weatherDoc = QJsonDocument::fromJson(weatherData, &error);
            if (error.error != QJsonParseError::NoError) {
                callback(Result<WeekWeatherData>::failure("Ошибка парсинга JSON с погодой: " + error.errorString().toStdString()));
                weatherReply->deleteLater();
                return;
            }

            if (!weatherDoc.isObject()) {
                callback(Result<WeekWeatherData>::failure("JSON с погодой не является объектом"));
                weatherReply->deleteLater();
                return;
            }

            QJsonObject json = weatherDoc.object();
            WeekWeatherData tmpResult = WeatherJsonConverter::parseWeekWeather(json);
            Result<WeekWeatherData> result;
            if (tmpResult.messageError.empty()) {
                result = Result<WeekWeatherData>::success(tmpResult);
            } else {
                result = Result<WeekWeatherData>::failure(tmpResult.messageError);
            }

            callback(result);

            weatherReply->deleteLater();
        });

        reply->deleteLater();
    });

    return ;
}
