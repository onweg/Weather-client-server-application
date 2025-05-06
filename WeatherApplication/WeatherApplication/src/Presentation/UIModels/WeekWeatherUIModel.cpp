#include "WeekWeatherUIModel.h"


WeekWeatherUiModel::WeekWeatherUiModel(QObject *parent) : QObject(parent) {}

QString WeekWeatherUiModel::city() const { return m_city; }

QString WeekWeatherUiModel::messageError() const { return m_messageError; }

QList<QObject *> WeekWeatherUiModel::dailyWeather() const { return m_dailyWeather; }

void WeekWeatherUiModel::setCity(const QString &val) {
    if (m_city != val) {
        m_city = val;
        emit cityChanged();
    }
}

void WeekWeatherUiModel::setMessageError(const QString &val) {
    if (m_messageError != val) {
        m_messageError = val;
        emit messageErrorChanged();
    }
}

void WeekWeatherUiModel::setDailyWeather(const QList<QObject *> &list) {
    m_dailyWeather = list;
    emit dailyWeatherChanged();
}

void WeekWeatherUiModel::clearDailyWeather() {
    qDeleteAll(m_dailyWeather);
    m_dailyWeather.clear();
    emit dailyWeatherChanged();
}

void WeekWeatherUiModel::addWeatherModel(QObject *model) {
    m_dailyWeather.append(model);
    emit dailyWeatherChanged();
}
