#include "WeatherJsonConverter.h"

WeatherJsonConverter::WeatherJsonConverter(QObject *parent)
    : QObject(parent)
{
}

WeatherData WeatherJsonConverter::parseWeatherDay(const QJsonObject &jsonObj)
{
    WeatherData data;
    if (!jsonObj.contains("list")) return data;

    QJsonArray forecasts = jsonObj["list"].toArray();
    if (forecasts.isEmpty()) return data;

    QJsonObject forecast = forecasts.first().toObject();
    data = createWeatherDataFromForecast(forecast);

    if (jsonObj.contains("city")) {
        data.city = jsonObj["city"].toObject()["name"].toString();
    }

    return data;
}

WeatherWeekData WeatherJsonConverter::parseWeatherWeek(const QJsonObject &jsonObj)
{
    WeatherWeekData weekData;

    if (!jsonObj.contains("list")) return weekData;

    QJsonArray forecasts = jsonObj["list"].toArray();
    QMap<QString, WeatherData> days;

    for (const QJsonValue &value : forecasts) {
        QJsonObject forecast = value.toObject();
        QString dateStr = QDateTime::fromString(forecast["dt_txt"].toString(), "yyyy-MM-dd HH:mm:ss").date().toString("yyyy-MM-dd");

        if (!days.contains(dateStr)) {
            days[dateStr] = createWeatherDataFromForecast(forecast);
        }
    }

    for (auto it = days.begin(); it != days.end(); ++it) {
        weekData.dailyForecasts.append(it.value());
    }

    if (jsonObj.contains("city")) {
        weekData.city = jsonObj["city"].toObject()["name"].toString();
    }

    return weekData;
}

UserData WeatherJsonConverter::parseUserData(const QJsonObject &jsonObj)
{
    UserData user;
    user.username = jsonObj["username"].toString();
    user.token = jsonObj["token"].toString();
    user.email = jsonObj["email"].toString();
    return user;
}

ApiReply WeatherJsonConverter::parseApiReply(const QJsonObject &jsonObj)
{
    ApiReply reply;
    reply.status = jsonObj["status"].toString();
    reply.message = jsonObj["message"].toString();
    reply.errorCode = jsonObj["error_code"].toInt();
    return reply;
}

WeatherData WeatherJsonConverter::createWeatherDataFromForecast(const QJsonObject &forecast)
{
    WeatherData data;
    QJsonObject main = forecast["main"].toObject();
    QJsonArray weatherArray = forecast["weather"].toArray();
    QJsonObject wind = forecast.contains("wind") ? forecast["wind"].toObject() : QJsonObject();

    if (!weatherArray.isEmpty()) {
        QJsonObject weather = weatherArray.first().toObject();
        data.description = weather["description"].toString();
        data.icon = weather["icon"].toString();
    }

    data.temp = main["temp"].toDouble();
    data.feels_like = main["feels_like"].toDouble();
    data.temp_min = main["temp_min"].toDouble();
    data.temp_max = main["temp_max"].toDouble();
    data.humidity = main["humidity"].toInt();
    data.pressure = main["pressure"].toInt();
    data.wind_speed = wind["speed"].toDouble();
    data.date = QDateTime::fromString(forecast["dt_txt"].toString(), "yyyy-MM-dd HH:mm:ss").date();

    return data;
}
