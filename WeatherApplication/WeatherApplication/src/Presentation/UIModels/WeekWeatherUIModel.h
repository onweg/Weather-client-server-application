#ifndef WEEKWEATHERUIMODEL_H
#define WEEKWEATHERUIMODEL_H

#include <QObject>
#include <QList>
#include <QString>
#include "WeatherUIModel.h"

class WeekWeatherUiModel : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString city READ city WRITE setCity NOTIFY cityChanged)
    Q_PROPERTY(QString messageError READ messageError WRITE setMessageError NOTIFY messageErrorChanged)
    Q_PROPERTY(QList<QObject*> dailyWeather READ dailyWeather NOTIFY dailyWeatherChanged)

public:
    explicit WeekWeatherUiModel(QObject* parent = nullptr) : QObject(parent) {}

    // === Getters ===
    QString city() const { return m_city; }
    QString messageError() const { return m_messageError; }
    QList<QObject*> dailyWeather() const { return m_dailyWeather; }

    // === Setters ===
    void setCity(const QString& val) {
        if (m_city != val) {
            m_city = val;
            emit cityChanged();
        }
    }

    void setMessageError(const QString& val) {
        if (m_messageError != val) {
            m_messageError = val;
            emit messageErrorChanged();
        }
    }

    void setDailyWeather(const QList<QObject*>& list) {
        m_dailyWeather = list;
        emit dailyWeatherChanged();
    }

    void clearDailyWeather() {
        qDeleteAll(m_dailyWeather);
        m_dailyWeather.clear();
        emit dailyWeatherChanged();
    }

    void addWeatherModel(QObject* model) {
        m_dailyWeather.append(model);
        emit dailyWeatherChanged();
    }

signals:
    void cityChanged();
    void messageErrorChanged();
    void dailyWeatherChanged();

private:
    QString m_city;
    QString m_messageError;
    QList<QObject*> m_dailyWeather;
};

#endif // WEEKWEATHERUIMODEL_H
