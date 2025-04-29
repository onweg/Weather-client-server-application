#include "WeekWeatherModel.h"

WeekWeatherModel::WeekWeatherModel(QObject *parent)
    : QObject(parent)
{
}

WeekWeatherModel::~WeekWeatherModel()
{
    clearDailyWeather();
}

void WeekWeatherModel::setData(const WeekWeatherData &data)
{
    clearDailyWeather();

    m_city = data.city;
    m_messageError = data.messageError;

    for (const auto &daily : data.dailyWeather) {
        m_dailyWeather.append(new WeatherModel(daily, this));
    }
}

QString WeekWeatherModel::getCity() const
{
    return m_city;
}

QString WeekWeatherModel::getMessageError() const
{
    return m_messageError;
}

QObject* WeekWeatherModel::getDailyWeatherModels() const
{
    WeatherModelList* list = new WeatherModelList(const_cast<WeekWeatherModel*>(this));
    for (auto* model : m_dailyWeather) {
        list->add(model);
    }
    return list;
}

void WeekWeatherModel::clearDailyWeather()
{
    qDeleteAll(m_dailyWeather);
    m_dailyWeather.clear();
}
