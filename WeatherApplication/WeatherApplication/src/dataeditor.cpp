#include "dataeditor.h"

DataEditor::DataEditor(QObject *parent) : QObject(parent)
{

}

QJsonObject DataEditor::getCorrectData(QJsonObject jsonObj)
{
    return processWeatherData(jsonObj);
}

QJsonObject DataEditor::processWeatherData(const QJsonObject &originalJson) {
    QJsonObject result;
    QDate currentDate = QDate::currentDate();

    if (originalJson.contains("city") && originalJson["city"].isObject()) {
        QJsonObject cityObj = originalJson["city"].toObject();
        result["city"] = cityObj["name"];

        if (cityObj.contains("country")) {
            result["country"] = cityObj["country"];
        }
    }

    if (originalJson.contains("list") && originalJson["list"].isArray()) {
        QJsonArray forecasts = originalJson["list"].toArray();
        QMap<QString, QJsonObject> dailyData;

        for (const QJsonValue &forecastValue : forecasts) {
            if (!forecastValue.isObject()) continue;
            QJsonObject forecast = forecastValue.toObject();

            QString dtTxt = forecast["dt_txt"].toString();
            QDateTime forecastTime = QDateTime::fromString(dtTxt, "yyyy-MM-dd HH:mm:ss");
            QString dateKey = forecastTime.date().toString("yyyy-MM-dd");

            QJsonObject mainData = forecast["main"].toObject();
            QJsonArray weatherArray = forecast["weather"].toArray();
            QJsonObject windData = forecast.contains("wind") ? forecast["wind"].toObject() : QJsonObject();

            QJsonObject dayData;

            dayData["temp"] = mainData["temp"];
            dayData["feels_like"] = mainData["feels_like"];
            dayData["temp_min"] = mainData["temp_min"];
            dayData["temp_max"] = mainData["temp_max"];

            if (!weatherArray.isEmpty()) {
                QJsonObject weather = weatherArray[0].toObject();
                dayData["description"] = weather["description"];
                dayData["icon"] = weather["icon"];
                dayData["main_weather"] = weather["main"];
            }

            dayData["wind_speed"] = windData["speed"];
            dayData["humidity"] = mainData["humidity"];
            dayData["pressure"] = mainData["pressure"];
            dayData["time"] = forecastTime.time().hour();

            if (forecastTime.date() == currentDate) {
                if (forecastTime.time().hour() >= 12) {
                    if (!dailyData.contains(dateKey) ||
                        (forecastTime.time().hour() <= 15 &&
                         forecastTime.time().hour() > dailyData[dateKey]["time"].toInt())) {
                        dailyData[dateKey] = dayData;
                    }
                }
            }
            else if (forecastTime.time().hour() == 15) {
                dailyData[dateKey] = dayData;
            }
        }

        QString todayKey = currentDate.toString("yyyy-MM-dd");
        if (!dailyData.contains(todayKey) && !forecasts.isEmpty()) {
            QJsonObject lastForecast = forecasts.last().toObject();
            QDateTime lastTime = QDateTime::fromString(lastForecast["dt_txt"].toString(), "yyyy-MM-dd HH:mm:ss");
            if (lastTime.date() == currentDate) {
                dailyData[todayKey] = createDayData(lastForecast);
            }
        }
        for (auto it = dailyData.begin(); it != dailyData.end(); ++it) {
            result[it.key()] = it.value();
        }
    }
    return result;
}

QJsonObject DataEditor::createDayData(const QJsonObject &forecast) {
    QJsonObject dayData;
    QJsonObject mainData = forecast["main"].toObject();
    QJsonArray weatherArray = forecast["weather"].toArray();
    QJsonObject windData = forecast.contains("wind") ? forecast["wind"].toObject() : QJsonObject();

    dayData["temp"] = mainData["temp"];
    dayData["feels_like"] = mainData["feels_like"];
    dayData["temp_min"] = mainData["temp_min"];
    dayData["temp_max"] = mainData["temp_max"];

    if (!weatherArray.isEmpty()) {
        QJsonObject weather = weatherArray[0].toObject();
        dayData["description"] = weather["description"];
        dayData["icon"] = weather["icon"];
    }

    dayData["wind_speed"] = windData["speed"];
    dayData["humidity"] = mainData["humidity"];
    dayData["pressure"] = mainData["pressure"];
    dayData["time"] = QDateTime::fromString(forecast["dt_txt"].toString(), "yyyy-MM-dd HH:mm:ss").time().hour();

    return dayData;
}
