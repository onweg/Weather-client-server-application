#include "WeatherJsonConverter.h"

WeatherJsonConverter::WeatherJsonConverter(QObject *parent)
    : QObject(parent)
{
}

WeekWeatherData WeatherJsonConverter::parseWeekWeather(const QJsonObject &jsonObj)
{
    WeekWeatherData weekData;
    if (!jsonObj.contains("list") || !jsonObj["list"].isArray()) {
        weekData.messageError = "Invalid JSON: no 'list' field.";
        return weekData;
    }
    QJsonArray forecasts = jsonObj["list"].toArray();
    QMap<QString, WeatherData> dailyData;
    QDate currentDate = QDate::currentDate();
    QString cityName = "";
    if (jsonObj.contains("city") && jsonObj["city"].isObject()) {
        QJsonObject cityObj = jsonObj["city"].toObject();
        cityName = cityObj["name"].toString();
    }
    for (const QJsonValue &forecastValue : forecasts) {
        if (!forecastValue.isObject()) continue;
        QJsonObject forecast = forecastValue.toObject();
        QString dtTxt = forecast["dt_txt"].toString();
        QDateTime forecastTime = QDateTime::fromString(dtTxt, "yyyy-MM-dd HH:mm:ss");
        QString dateKey = forecastTime.date().toString("yyyy-MM-dd");
        if (!forecast.contains("main") || !forecast.contains("weather")) continue;
        QJsonObject mainData = forecast["main"].toObject();
        QJsonArray weatherArray = forecast["weather"].toArray();
        QJsonObject windData = forecast.contains("wind") ? forecast["wind"].toObject() : QJsonObject();
        WeatherData data;
        data.city = cityName;
        data.date = forecastTime.date();
        data.temp = mainData["temp"].toDouble();
        data.feels_like = mainData["feels_like"].toDouble();
        data.temp_min = mainData["temp_min"].toDouble();
        data.temp_max = mainData["temp_max"].toDouble();
        data.humidity = mainData["humidity"].toInt();
        data.pressure = mainData["pressure"].toInt();
        data.wind_speed = windData["speed"].toDouble();
        if (!weatherArray.isEmpty()) {
            QJsonObject weather = weatherArray.first().toObject();
            data.description = weather["description"].toString();
        }
        int hour = forecastTime.time().hour();
        if (forecastTime.date() == currentDate) {
            if (hour >= 12) {
                if (!dailyData.contains(dateKey) || (abs(15 - hour) < abs(15 - dailyData[dateKey].date.day()))) {
                    dailyData[dateKey] = data;
                }
            }
        } else {
            if (hour == 15) {
                dailyData[dateKey] = data;
            }
        }
    }
    weekData.city = cityName;
    QStringList sortedKeys = dailyData.keys();
    std::sort(sortedKeys.begin(), sortedKeys.end());
    for (const QString &key : sortedKeys) {
        weekData.dailyWeather.append(dailyData[key]);
    }
    return weekData;
}

AuthorizationReply WeatherJsonConverter::parseAuthorizationReply(const QJsonObject &jsonObj) {
    AuthorizationReply reply;
    if (!jsonObj.contains("status") || !jsonObj["status"].isString()) {
        reply.success = false;
        reply.message = "Invalid JSON: no 'status' field or invalid type.";
        return reply;
    }
    QString status = jsonObj["status"].toString();
    if (status == "success") {
        reply.success = true;
    } else if (status == "error") {
        reply.success = false;
    } else {
        reply.success = false;
        reply.message = "Invalid JSON: unknown 'status' value.";
        return reply;
    }
    if (!jsonObj.contains("message") || !jsonObj["message"].isString()) {
        reply.success = false;
        reply.message = "Invalid JSON: no 'message' field or invalid type.";
        return reply;
    }

    reply.message = jsonObj["message"].toString();

    return reply;
}
