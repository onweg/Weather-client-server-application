#include "weatherjsonconverter.h"

WeatherJsonConverter::WeatherJsonConverter(QObject *parent)
    : QObject(parent)
{
}

WeekWeatherData WeatherJsonConverter::parseWeekWeather(const QJsonObject &jsonObj)
{
    WeekWeatherData weekData;

    // Проверяем наличие ключа "list" и его тип
    if (!jsonObj.contains("list") || !jsonObj["list"].isArray()) {
        weekData.messageError = "Invalid JSON: no 'list' field.";
        return weekData;
    }

    // Извлекаем массив прогнозов
    QJsonArray forecasts = jsonObj["list"].toArray();

    // Карта для хранения данных по дням
    QMap<QString, WeatherData> dailyData;

    // Текущая дата
    QDate currentDate = QDate::currentDate();

    // Извлекаем название города (если есть)
    QString cityName = "";
    if (jsonObj.contains("city") && jsonObj["city"].isObject()) {
        QJsonObject cityObj = jsonObj["city"].toObject();
        cityName = cityObj["name"].toString();
    }

    // Обрабатываем каждый прогноз
    for (const QJsonValue &forecastValue : forecasts) {
        if (!forecastValue.isObject()) continue;

        QJsonObject forecast = forecastValue.toObject();

        // Извлекаем дату и время прогноза
        QString dtTxt = forecast["dt_txt"].toString();
        QDateTime forecastTime = QDateTime::fromString(dtTxt, "yyyy-MM-dd HH:mm:ss");
        QString dateKey = forecastTime.date().toString("yyyy-MM-dd");

        // Проверяем наличие необходимых полей
        if (!forecast.contains("main") || !forecast.contains("weather")) continue;

        QJsonObject mainData = forecast["main"].toObject();
        QJsonArray weatherArray = forecast["weather"].toArray();
        QJsonObject windData = forecast.contains("wind") ? forecast["wind"].toObject() : QJsonObject();

        // Создаем объект WeatherData
        WeatherData data;
        data.city = cityName; // Устанавливаем название города
        data.date = forecastTime.date();
        data.temp = mainData["temp"].toDouble();
        data.feels_like = mainData["feels_like"].toDouble();
        data.temp_min = mainData["temp_min"].toDouble();
        data.temp_max = mainData["temp_max"].toDouble();
        data.humidity = mainData["humidity"].toInt();
        data.pressure = mainData["pressure"].toInt();
        data.wind_speed = windData["speed"].toDouble();

        // Добавляем описание погоды
        if (!weatherArray.isEmpty()) {
            QJsonObject weather = weatherArray.first().toObject();
            data.description = weather["description"].toString();
        }

        // Определяем время суток
        int hour = forecastTime.time().hour();

        // Добавляем данные только для нужных временных интервалов
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

    // Сохраняем название города в WeekWeatherData
    weekData.city = cityName;

    // Сортируем дни по возрастанию даты
    QStringList sortedKeys = dailyData.keys();
    std::sort(sortedKeys.begin(), sortedKeys.end());

    // Добавляем данные в WeekWeatherData
    for (const QString &key : sortedKeys) {
        weekData.dailyWeather.append(dailyData[key]);
    }

    return weekData;
}

AuthorizationReply WeatherJsonConverter::parseAuthorizationReply(const QJsonObject &jsonObj) {
    AuthorizationReply reply;

    // Проверяем наличие ключа "status" и его значение
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

    // Проверяем наличие ключа "message" и его значение
    if (!jsonObj.contains("message") || !jsonObj["message"].isString()) {
        reply.success = false;
        reply.message = "Invalid JSON: no 'message' field or invalid type.";
        return reply;
    }

    reply.message = jsonObj["message"].toString();

    return reply;
}
// #include "WeatherJsonConverter.h"

// WeatherJsonConverter::WeatherJsonConverter(QObject *parent)
//     : QObject(parent)
// {
// }

// WeatherData WeatherJsonConverter::parseWeatherDay(const QJsonObject &jsonObj)
// {
//     WeatherData data;
//     if (!jsonObj.contains("list")) return data;

//     QJsonArray forecasts = jsonObj["list"].toArray();
//     if (forecasts.isEmpty()) return data;

//     QJsonObject forecast = forecasts.first().toObject();
//     data = createWeatherDataFromForecast(forecast);

//     if (jsonObj.contains("city")) {
//         data.city = jsonObj["city"].toObject()["name"].toString();
//     }

//     return data;
// }

// WeatherWeekData WeatherJsonConverter::parseWeatherWeek(const QJsonObject &jsonObj)
// {
//     WeatherWeekData weekData;

//     if (!jsonObj.contains("list")) return weekData;

//     QJsonArray forecasts = jsonObj["list"].toArray();
//     QMap<QString, WeatherData> days;

//     for (const QJsonValue &value : forecasts) {
//         QJsonObject forecast = value.toObject();
//         QString dateStr = QDateTime::fromString(forecast["dt_txt"].toString(), "yyyy-MM-dd HH:mm:ss").date().toString("yyyy-MM-dd");

//         if (!days.contains(dateStr)) {
//             days[dateStr] = createWeatherDataFromForecast(forecast);
//         }
//     }

//     for (auto it = days.begin(); it != days.end(); ++it) {
//         weekData.dailyForecasts.append(it.value());
//     }

//     if (jsonObj.contains("city")) {
//         weekData.city = jsonObj["city"].toObject()["name"].toString();
//     }

//     return weekData;
// }

// UserData WeatherJsonConverter::parseUserData(const QJsonObject &jsonObj)
// {
//     UserData user;
//     user.username = jsonObj["username"].toString();
//     user.token = jsonObj["token"].toString();
//     user.email = jsonObj["email"].toString();
//     return user;
// }

// ApiReply WeatherJsonConverter::parseApiReply(const QJsonObject &jsonObj)
// {
//     ApiReply reply;
//     reply.status = jsonObj["status"].toString();
//     reply.message = jsonObj["message"].toString();
//     reply.errorCode = jsonObj["error_code"].toInt();
//     return reply;
// }

// WeatherData WeatherJsonConverter::createWeatherDataFromForecast(const QJsonObject &forecast)
// {
//     WeatherData data;
//     QJsonObject main = forecast["main"].toObject();
//     QJsonArray weatherArray = forecast["weather"].toArray();
//     QJsonObject wind = forecast.contains("wind") ? forecast["wind"].toObject() : QJsonObject();

//     if (!weatherArray.isEmpty()) {
//         QJsonObject weather = weatherArray.first().toObject();
//         data.description = weather["description"].toString();
//         data.icon = weather["icon"].toString();
//     }

//     data.temp = main["temp"].toDouble();
//     data.feels_like = main["feels_like"].toDouble();
//     data.temp_min = main["temp_min"].toDouble();
//     data.temp_max = main["temp_max"].toDouble();
//     data.humidity = main["humidity"].toInt();
//     data.pressure = main["pressure"].toInt();
//     data.wind_speed = wind["speed"].toDouble();
//     data.date = QDateTime::fromString(forecast["dt_txt"].toString(), "yyyy-MM-dd HH:mm:ss").date();

//     return data;
// }
