#include "clientcontroller.h"

ClientController::ClientController(QObject *parent) : QObject(parent)
{

}

void ClientController::getDataSearchCity(const QString &data)
{
    qDebug() << "Полученная строка: " << data;
    emit cityChange(data);
}

void ClientController::slotWeatherData(const QJsonObject &jsonObj)
{
    setData(jsonObj);
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
    // Очищаем предыдущие данные
    weatherData = WeatherData();

    // Обработка данных о городе
    if (jsonObj.contains("city") && jsonObj["city"].isObject()) {
        QJsonObject cityObject = jsonObj["city"].toObject();
        weatherData.city = cityObject["name"].toString(); // Название города
    }

    // Обработка данных из массива "list"
    if (jsonObj.contains("list") && jsonObj["list"].isArray()) {
        QJsonArray listArray = jsonObj["list"].toArray();
        if (!listArray.isEmpty()) {
            QJsonObject firstDay = listArray[0].toObject();

            // Дата (преобразуем Unix timestamp в QDate)
            if (firstDay.contains("dt")) {
                qint64 timestamp = firstDay["dt"].toInt(); // Получаем timestamp
                QDateTime dateTime;
                dateTime.setTime_t(static_cast<uint>(timestamp)); // Преобразуем в QDateTime
                weatherData.date = dateTime.date(); // Извлекаем дату
            }

            // Основные данные о погоде
            if (firstDay.contains("main") && firstDay["main"].isObject()) {
                QJsonObject mainObject = firstDay["main"].toObject();
                weatherData.temp = mainObject["temp"].toDouble(); // Температура
                weatherData.feels_like = mainObject["feels_like"].toDouble(); // Ощущается как
                weatherData.temp_max = mainObject["temp_max"].toDouble(); // Максимальная температура
                weatherData.temp_min = mainObject["temp_min"].toDouble(); // Минимальная температура
                weatherData.humidity = mainObject["humidity"].toInt(); // Влажность
                weatherData.pressure = mainObject["pressure"].toInt(); // Давление
            }

            // Описание погоды
            if (firstDay.contains("weather") && firstDay["weather"].isArray()) {
                QJsonArray weatherArray = firstDay["weather"].toArray();
                if (!weatherArray.isEmpty()) {
                    QJsonObject weatherObject = weatherArray[0].toObject();
                    weatherData.description = weatherObject["description"].toString(); // Описание погоды
                }
            }

            // Скорость ветра
            if (firstDay.contains("wind") && firstDay["wind"].isObject()) {
                QJsonObject windObject = firstDay["wind"].toObject();
                weatherData.wind_speed = windObject["speed"].toDouble(); // Скорость ветра
            }
        }
    }
    emit dataUpdated();
}

void ClientController::setData(const QString &city, const QDate &date)
{
    // тут уже используется для нажаьтия кнопок след дня или предыдущего дня
    // отправиться в WeatherManager запросить у кеша данные на определенный город и определенную дату
    return;
}

