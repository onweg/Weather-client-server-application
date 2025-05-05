#include "WeatherDataDto.h"

WeatherDataDto::WeatherDataDto(QObject *parent)
    : QObject(parent)
{
}

// === GETTERS ===
QString WeatherDataDto::getCity() const
{
    return m_city;
}

QString WeatherDataDto::getDate() const
{
    return m_date;
}

QString WeatherDataDto::getDescription() const
{
    return m_description;
}

double WeatherDataDto::getTemp() const
{
    return m_temp;
}

double WeatherDataDto::getFeelsLike() const
{
    return m_feelsLike;
}

double WeatherDataDto::getTempMax() const
{
    return m_tempMax;
}

double WeatherDataDto::getTempMin() const
{
    return m_tempMin;
}

double WeatherDataDto::getWindSpeed() const
{
    return m_windSpeed;
}

int WeatherDataDto::getHumidity() const
{
    return m_humidity;
}

int WeatherDataDto::getPressure() const
{
    return m_pressure;
}

QString WeatherDataDto::getMessageError() const
{
    return m_messageError;
}

// === SETTERS с уведомлением через dataChanged ===
void WeatherDataDto::setCity(const QString& city)
{
    if (m_city != city) {
        m_city = city;
        emit dataChanged();
    }
}

void WeatherDataDto::setDate(const QString& date)
{
    if (m_date != date) {
        m_date = date;
        emit dataChanged();
    }
}

void WeatherDataDto::setDescription(const QString& description)
{
    if (m_description != description) {
        m_description = description;
        emit dataChanged();
    }
}

void WeatherDataDto::setTemp(double temp)
{
    if (qFuzzyCompare(m_temp, temp)) {
        return;
    }
    m_temp = temp;
    emit dataChanged();
}

void WeatherDataDto::setFeelsLike(double feelsLike)
{
    if (qFuzzyCompare(m_feelsLike, feelsLike)) {
        return;
    }
    m_feelsLike = feelsLike;
    emit dataChanged();
}

void WeatherDataDto::setTempMax(double tempMax)
{
    if (qFuzzyCompare(m_tempMax, tempMax)) {
        return;
    }
    m_tempMax = tempMax;
    emit dataChanged();
}

void WeatherDataDto::setTempMin(double tempMin)
{
    if (qFuzzyCompare(m_tempMin, tempMin)) {
        return;
    }
    m_tempMin = tempMin;
    emit dataChanged();
}

void WeatherDataDto::setWindSpeed(double windSpeed)
{
    if (qFuzzyCompare(m_windSpeed, windSpeed)) {
        return;
    }
    m_windSpeed = windSpeed;
    emit dataChanged();
}

void WeatherDataDto::setHumidity(int humidity)
{
    if (m_humidity == humidity) {
        return;
    }
    m_humidity = humidity;
    emit dataChanged();
}

void WeatherDataDto::setPressure(int pressure)
{
    if (m_pressure == pressure) {
        return;
    }
    m_pressure = pressure;
    emit dataChanged();
}

void WeatherDataDto::setMessageError(const QString& messageError)
{
    if (m_messageError == messageError) {
        return;
    }
    m_messageError = messageError;
    emit dataChanged();
}
