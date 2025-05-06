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
    explicit WeekWeatherUiModel(QObject* parent = nullptr);

    QString city() const;
    QString messageError() const;
    QList<QObject*> dailyWeather() const;
    void setCity(const QString& val);
    void setMessageError(const QString& val);
    void setDailyWeather(const QList<QObject*>& list);
    void clearDailyWeather();
    void addWeatherModel(QObject* model);

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
