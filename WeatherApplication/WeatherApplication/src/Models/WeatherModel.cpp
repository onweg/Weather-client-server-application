#include "WeatherModel.h"

WeatherModel::WeatherModel(QObject *parent)
    : QObject(parent), m_data{}
{
}

WeatherModel::WeatherModel(const WeatherData &data, QObject *parent)
    : QObject(parent), m_data(data)
{
}

void WeatherModel::setData(const WeatherData &data)
{
    m_data = data;
}

const WeatherData& WeatherModel::getData() const {
    return m_data;
}

QString WeatherModel::getCity() const {
    return m_data.city;
}

QString WeatherModel::getDate() const {
    return m_data.date.toString("yyyy-MM-dd");
}


QString WeatherModel::getDescription() const {
    return m_data.description;
}

double WeatherModel::getTemp() const {
    return m_data.temp;
}

double WeatherModel::getFeelsLike() const {
    return m_data.feels_like;
}

double WeatherModel::getTempMax() const {
    return m_data.temp_max;
}

double WeatherModel::getTempMin() const {
    return m_data.temp_min;
}

double WeatherModel::getWindSpeed() const {
    return m_data.wind_speed;
}

int WeatherModel::getHumidity() const {
    return m_data.humidity;
}

int WeatherModel::getPressure() const {
    return m_data.pressure;
}

QString WeatherModel::getMessageError() const {
    return m_data.messageError;
}
