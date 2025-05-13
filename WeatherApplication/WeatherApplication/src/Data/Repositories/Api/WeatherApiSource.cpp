#include "WeatherApiSource.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QString>

#include "../../../Utils/WeatherJsonConverter.h"
#include "../../DtoModels/WeekWeatherDataDto"

WeatherApiSource::WeatherApiSource(std::shared_ptr<IConfigProvider> config, QObject *parent)
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

    std::string errorMsg;
    if (!isApiConfigValid(errorMsg)) {
        callback(Result<WeekWeatherData>::failure(errorMsg));
        return;
    }

    QString cityUrl = buildCitySearchUrl(city);

    makeRequest(QUrl(cityUrl), [this, callback](QByteArray cityResponse, QString error) {
        if (!error.isEmpty()) {
            callback(Result<WeekWeatherData>::failure(error.toStdString()));
            return;
        }

        auto coordsResult = parseCityCoordinates(cityResponse);
        if (!coordsResult.isSuccess()) {
            callback(Result<WeekWeatherData>::failure(coordsResult.error()));
            return;
        }

        auto [lat, lon] = coordsResult.value();
        QString weatherUrl = buildWeatherUrl(lat, lon);

        makeRequest(QUrl(weatherUrl), [this, callback](QByteArray weatherData, QString error) {
            if (!error.isEmpty()) {
                callback(Result<WeekWeatherData>::failure(error.toStdString()));
                return;
            }

            auto result = parseWeatherData(weatherData);
            callback(result);
        });
    });
}

// ----------------- HELPER METHODS -----------------

bool WeatherApiSource::isApiConfigValid(std::string &errorMsg) const {
    if (!apiConfig_.isSuccess()) {
        errorMsg = "Конфигурация API недоступна";
        return false;
    }
    return true;
}

QString WeatherApiSource::buildCitySearchUrl(const std::string &city) const {
    QString cityName = QString::fromStdString(city);
    QString urlTemplate = QString::fromStdString(apiConfig_.value().urlFindCityByName);
    return urlTemplate.arg(cityName, QString::fromStdString(apiConfig_.value().key));
}

QString WeatherApiSource::buildWeatherUrl(double lat, double lon) const {
    QString urlTemplate = QString::fromStdString(apiConfig_.value().urlFindWeatherByCoordinates);
    return urlTemplate.arg(QString::number(lat), QString::number(lon), QString::fromStdString(apiConfig_.value().key));
}

void WeatherApiSource::makeRequest(const QUrl &url, std::function<void(QByteArray, QString)> callback) {
    QNetworkRequest request(url);
    QNetworkReply *reply = networkManager_->get(request);

    connect(reply, &QNetworkReply::finished, this, [reply, callback]() {
        if (reply->error() != QNetworkReply::NoError) {
            callback({}, reply->errorString());
        } else {
            callback(reply->readAll(), "");
        }
        reply->deleteLater();
    });
}

Result<QPair<double, double>> WeatherApiSource::parseCityCoordinates(const QByteArray &data) const {
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(data, &error);
    if (error.error != QJsonParseError::NoError) {
        return Result<QPair<double, double>>::failure("Ошибка парсинга JSON: " + error.errorString().toStdString());
    }

    if (!doc.isArray()) {
        return Result<QPair<double, double>>::failure("Ожидался массив JSON");
    }

    QJsonArray array = doc.array();
    if (array.isEmpty()) {
        return Result<QPair<double, double>>::failure("Город не найден");
    }

    QJsonObject obj = array[0].toObject();
    double lat = obj["lat"].toDouble();
    double lon = obj["lon"].toDouble();

    return Result<QPair<double, double>>::success({lat, lon});
}

Result<WeekWeatherData> WeatherApiSource::parseWeatherData(const QByteArray &data) const {
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(data, &error);
    if (error.error != QJsonParseError::NoError) {
        return Result<WeekWeatherData>::failure("Ошибка парсинга JSON с погодой: " + error.errorString().toStdString());
    }

    if (!doc.isObject()) {
        return Result<WeekWeatherData>::failure("JSON с погодой не является объектом");
    }

    QJsonObject obj = doc.object();
    WeekWeatherDataDto dto = WeatherJsonConverter::parseWeekWeather(obj);
    if (!dto.messageError.empty()) {
        return Result<WeekWeatherData>::failure(dto.messageError);
    }

    return Result<WeekWeatherData>::success(dto);
}
