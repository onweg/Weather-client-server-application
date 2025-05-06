#include "WeatherApiSource.h"

WeatherApiSource::WeatherApiSource(QObject* parent)
    : QObject(parent), manager_(new QNetworkAccessManager(this)) {}

void WeatherApiSource::setConfig(const ApiConfig& config) {
    apiConfig_ = config;
}

void WeatherApiSource::findWeatherByCity(const std::string city, const std::string date,
                                         std::function<void(Result<WeatherData>)> callback) {
    dayCallback_ = callback;
    requestedDate_ = date;
    requestedCity_ = city;

    QString url = apiConfig_.urlFindCityByName.arg(QString::fromStdString(city)).arg(apiConfig_.key);
    QNetworkRequest request(QUrl(url));
    replyCity_ = manager_->get(request);
    connect(replyCity_, &QNetworkReply::finished, this, &WeatherApiSource::onCityFound);
}

void WeatherApiSource::findWeekWeatherByCity(const std::string city,
                                             std::function<void(Result<WeekWeatherData>)> callback) {
    weekCallback_ = callback;
    requestedCity_ = city;

    QString url = apiConfig_.urlFindCityByName.arg(QString::fromStdString(city)).arg(apiConfig_.key);
    QNetworkRequest request(QUrl(url));
    replyCity_ = manager_->get(request);
    connect(replyCity_, &QNetworkReply::finished, this, &WeatherApiSource::onCityFound);
}

void WeatherApiSource::onCityFound() {
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
    if (!reply) return;

    QByteArray data = reply->readAll();
    reply->deleteLater();

    QJsonParseError jsonError;
    QJsonDocument doc = QJsonDocument::fromJson(data, &jsonError);
    if (jsonError.error != QJsonParseError::NoError || !doc.isArray() || doc.array().isEmpty()) {
        if (dayCallback_) dayCallback_(Result<WeatherData>::Error("City not found or invalid JSON"));
        if (weekCallback_) weekCallback_(Result<WeekWeatherData>::Error("City not found or invalid JSON"));
        return;
    }

    QJsonObject cityObj = doc.array().at(0).toObject();
    QString lat = QString::number(cityObj["lat"].toDouble());
    QString lon = QString::number(cityObj["lon"].toDouble());

    requestWeatherByCoords(lat, lon);
}

void WeatherApiSource::requestWeatherByCoords(const QString& lat, const QString& lon) {
    QString url = apiConfig_.urlFindWeatherByCoordinates.arg(lat).arg(lon).arg(apiConfig_.key);
    QNetworkRequest request(QUrl(url));
    replyWeather_ = manager_->get(request);
    connect(replyWeather_, &QNetworkReply::finished, this, &WeatherApiSource::onWeatherReceived);
}

void WeatherApiSource::onWeatherReceived() {
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
    if (!reply) return;

    QByteArray data = reply->readAll();
    reply->deleteLater();

    QJsonParseError jsonError;
    QJsonDocument doc = QJsonDocument::fromJson(data, &jsonError);
    if (jsonError.error != QJsonParseError::NoError || !doc.isObject()) {
        if (dayCallback_) dayCallback_(Result<WeatherData>::Error("Invalid weather JSON"));
        if (weekCallback_) weekCallback_(Result<WeekWeatherData>::Error("Invalid weather JSON"));
        return;
    }

    QJsonObject rootObj = doc.object();

    if (dayCallback_) {
        Result<WeatherData> result = parseDayWeather(rootObj, requestedDate_);
        dayCallback_(result);
    }

    if (weekCallback_) {
        Result<WeekWeatherData> result = parseWeekWeather(rootObj);
        weekCallback_(result);
    }
}

Result<WeatherData> WeatherApiSource::parseDayWeather(const QJsonObject& json, const std::string& date) {
    // TODO: parse actual data and convert it to WeatherData
    WeatherData data;
    data.cityName = requestedCity_;
    data.date = date;
    data.temperature = json["current"]["temp"].toDouble();
    return Result<WeatherData>::Success(data);
}

Result<WeekWeatherData> WeatherApiSource::parseWeekWeather(const QJsonObject& json) {
    // TODO: parse actual data and convert it to WeekWeatherData
    WeekWeatherData data;
    data.cityName = requestedCity_;
    const QJsonArray& daily = json["daily"].toArray();
    for (const auto& item : daily) {
        WeatherData day;
        day.temperature = item.toObject()["temp"].toObject()["day"].toDouble();
        data.days.push_back(day);
    }
    return Result<WeekWeatherData>::Success(data);
}
