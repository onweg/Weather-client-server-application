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

    // 1. Извлекаем город
    if (originalJson.contains("city") && originalJson["city"].isObject()) {
        QJsonObject cityObj = originalJson["city"].toObject();
        result["city"] = cityObj["name"];

        // Добавляем страну, если есть
        if (cityObj.contains("country")) {
            result["country"] = cityObj["country"];
        }
    }

    // 2. Обрабатываем прогнозы
    if (originalJson.contains("list") && originalJson["list"].isArray()) {
        QJsonArray forecasts = originalJson["list"].toArray();
        QMap<QString, QJsonObject> dailyData;

        for (const QJsonValue &forecastValue : forecasts) {
            if (!forecastValue.isObject()) continue;
            QJsonObject forecast = forecastValue.toObject();

            // Парсим дату и время
            QString dtTxt = forecast["dt_txt"].toString();
            QDateTime forecastTime = QDateTime::fromString(dtTxt, "yyyy-MM-dd HH:mm:ss");
            QString dateKey = forecastTime.date().toString("yyyy-MM-dd");

            // Основные данные прогноза
            QJsonObject mainData = forecast["main"].toObject();
            QJsonArray weatherArray = forecast["weather"].toArray();
            QJsonObject windData = forecast.contains("wind") ? forecast["wind"].toObject() : QJsonObject();

            // Формируем объект с данными дня
            QJsonObject dayData;

            // Температура и ощущения
            dayData["temp"] = mainData["temp"];
            dayData["feels_like"] = mainData["feels_like"];
            dayData["temp_min"] = mainData["temp_min"];
            dayData["temp_max"] = mainData["temp_max"];

            // Погодные условия
            if (!weatherArray.isEmpty()) {
                QJsonObject weather = weatherArray[0].toObject();
                dayData["description"] = weather["description"];
                dayData["icon"] = weather["icon"];
                dayData["main_weather"] = weather["main"];
            }

            // Ветер и атмосфера
            dayData["wind_speed"] = windData["speed"];
            dayData["humidity"] = mainData["humidity"];
            dayData["pressure"] = mainData["pressure"];

            // Время прогноза (для отладки)
            dayData["time"] = forecastTime.time().hour();

            // Логика выбора прогноза (ваша оригинальная)
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

        // Резервный вариант для сегодняшнего дня
        QString todayKey = currentDate.toString("yyyy-MM-dd");
        if (!dailyData.contains(todayKey) && !forecasts.isEmpty()) {
            QJsonObject lastForecast = forecasts.last().toObject();
            QDateTime lastTime = QDateTime::fromString(lastForecast["dt_txt"].toString(), "yyyy-MM-dd HH:mm:ss");
            if (lastTime.date() == currentDate) {
                dailyData[todayKey] = createDayData(lastForecast);
            }
        }

        // Переносим в результат
        for (auto it = dailyData.begin(); it != dailyData.end(); ++it) {
            result[it.key()] = it.value();
        }
    }

    return result;
}

// Вспомогательная функция для создания объекта дня (опционально)
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

// принимаем огромный json файл
// оставляем только данные о следующих параметрах
//    struct WeatherData{
//        QString city;
//        QDate date;
//        QString description;
//        double temp;
//        double feels_like;
//        double temp_max;
//        double temp_min;
//        double wind_speed;
//        int humidity;
//        int pressure;
//    };


/*
    weatherData = WeatherData();
    if (jsonObj.contains("error")) {
        weatherData.city = jsonObj["error"].toString();
        weatherData.description = "...";
        emit dataUpdated();
        return ;
    }
    if (jsonObj.contains("city") && jsonObj["city"].isObject()) {
        QJsonObject cityObject = jsonObj["city"].toObject();
        weatherData.city = cityObject["name"].toString();
    }
    if (jsonObj.contains("list") && jsonObj["list"].isArray()) {
        QJsonArray listArray = jsonObj["list"].toArray();
        if (!listArray.isEmpty()) {
            QJsonObject firstDay = listArray[0].toObject();
            if (firstDay.contains("dt")) {
                qint64 timestamp = firstDay["dt"].toInt();
                QDateTime dateTime;
                dateTime.setTime_t(static_cast<uint>(timestamp));
                weatherData.date = dateTime.date();
            }
            if (firstDay.contains("main") && firstDay["main"].isObject()) {
                QJsonObject mainObject = firstDay["main"].toObject();
                weatherData.temp = mainObject["temp"].toDouble();
                weatherData.feels_like = mainObject["feels_like"].toDouble();
                weatherData.temp_max = mainObject["temp_max"].toDouble();
                weatherData.temp_min = mainObject["temp_min"].toDouble();
                weatherData.humidity = mainObject["humidity"].toInt();
                weatherData.pressure = mainObject["pressure"].toInt();
            }
            if (firstDay.contains("weather") && firstDay["weather"].isArray()) {
                QJsonArray weatherArray = firstDay["weather"].toArray();
                if (!weatherArray.isEmpty()) {
                    QJsonObject weatherObject = weatherArray[0].toObject();
                    weatherData.description = weatherObject["description"].toString();
                }
            }
            if (firstDay.contains("wind") && firstDay["wind"].isObject()) {
                QJsonObject windObject = firstDay["wind"].toObject();
                weatherData.wind_speed = windObject["speed"].toDouble(); // Скорость ветра
            }
        }
    }
    emit dataUpdated();
 */

//{
//    city: name
//    "сегодняшняя дата в строковом формтае(date.toString())": {
//        description: description
//        temp: temp_value
//        ...
//    }
//    "завтрашняя дата в строковом формтае(date.toString())": {
//        description: description
//        temp: temp_value
//        ...
//    }
//    "завтрашняя дата в строковом формтае(date.toString())": {
//        description: description
//        temp: temp_value
//        ...
//    }
//    ...
//}
