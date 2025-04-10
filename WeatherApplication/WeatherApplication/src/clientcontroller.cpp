#include "clientcontroller.h"

ClientController::ClientController(QObject *parent) : QObject(parent)
{

}

void ClientController::clickSearchCityButton(const QString &city)
{
    emit findWeatherData(city);
}

void ClientController::clickNextDayButton()
{
    setNextDay();
    qDebug() << weatherData.city << " " << weatherData.date.toString("yyyy-MM-dd");
    emit findWeatherData(weatherData.city, weatherData.date);
}

void ClientController::clickPrevDayButton()
{
    setPrevDay();
    emit findWeatherData(weatherData.city, weatherData.date);
}

void ClientController::slotWeatherDataArrived(const QJsonObject &jsonObj)
{
    qDebug() << "Получил";
    setData(jsonObj);
}


QString ClientController::getCity()
{
    return weatherData.city;
}

QString ClientController::getDate()
{
    return weatherData.date.toString("yyyy-MM-dd");
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
    weatherData.city = jsonObj["city"].toString();
    weatherData.date = QDate::fromString(jsonObj["date"].toString(), "yyyy-MM-dd");
    weatherData.description = jsonObj["description"].toString();
    weatherData.temp = jsonObj["temp"].toDouble();
    weatherData.feels_like = jsonObj["feels_like"].toDouble();
    weatherData.temp_max = jsonObj["temp_max"].toDouble();
    weatherData.temp_min = jsonObj["temp_min"].toDouble();
    weatherData.wind_speed = jsonObj["wind_speed"].toDouble();
    weatherData.humidity = jsonObj["humidity"].toInt();
    weatherData.pressure = jsonObj["pressure"].toInt();
    emit dataUpdated();
}

void ClientController::setNextDay()
{
    if (!weatherData.date.isValid()) {
        weatherData.date = QDate();
    }
    weatherData.date = weatherData.date.addDays(1);
    return;
}

void ClientController::setPrevDay()
{
    if (!weatherData.date.isValid()) {
        weatherData.date = QDate();
    }
    weatherData.date = weatherData.date.addDays(-1);
    return;
}



