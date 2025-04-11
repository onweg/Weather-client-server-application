#include "clientcontroller.h"

ClientController::ClientController(QObject *parent) : QObject(parent)
{

}

void ClientController::clickSearchCityButton(const QString &city)
{
    emit findWeatherData(city);
}

void ClientController::clickNextDayButton(const QString &city, const QString &date)
{
    // обработать дану (потому что прислал в виде строки)
    // findWeatherData(city, date + 1);
}

void ClientController::clickPrevDayButton(const QString &city, const QString &date)
{
    // обработать дану (потому что прислал в виде строки)
    // findWeatherData(city, date - 1);
}

void ClientController::slotWeatherDataArrived(const QJsonObject &jsonObj)
{
    setData(jsonObj);
}


QString ClientController::getCity()
{
    return weatherData.city;
}

QString ClientController::getDate()
{
    return weatherData.date.toString();
}

QString ClientController::getDescription()
{
    return weatherData.description;
}

QString ClientController::getTemp()
{
    return QString::number(weatherData.temp, 'f', 1);
}

QString ClientController::getFeelsLike()
{
    return QString::number(weatherData.feels_like, 'f', 1);
}

QString ClientController::getTempMax()
{
    return QString::number(weatherData.temp_max, 'f', 1);
}

QString ClientController::getTempMin()
{
    return QString::number(weatherData.temp_min, 'f', 1);
}

QString ClientController::getWindSpeed()
{
    return QString::number(weatherData.wind_speed, 'f', 1);
}

QString ClientController::getHumidity()
{
    return QString::number(weatherData.humidity);
}

QString ClientController::getPressure()
{
    return QString::number(weatherData.pressure);
}

void ClientController::setData(const QJsonObject &jsonObj) {

}

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

