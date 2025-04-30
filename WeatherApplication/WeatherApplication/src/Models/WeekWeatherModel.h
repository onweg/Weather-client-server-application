#ifndef WEEKWEATHERMODEL_H
#define WEEKWEATHERMODEL_H

#include <QObject>
#include <QString>
#include <QList>
#include <QDebug>
#include "WeatherModel.h"
#include "WeatherModeList.h"
#include "../Types/WeekWeatherData.h"


class WeekWeatherModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString city READ getCity CONSTANT)
    Q_PROPERTY(QObject* dailyWeather READ getDailyWeatherModels CONSTANT)
    Q_PROPERTY(QString messageError READ getMessageError CONSTANT)

public:
    explicit WeekWeatherModel(QObject *parent = nullptr);
    ~WeekWeatherModel();

    void setData(const WeekWeatherData &data);

    QString getCity() const;
    QString getMessageError() const;
    QObject* getDailyWeatherModels() const;

private:
    void clearDailyWeather();

    QString m_city;
    QString m_messageError;
    QList<WeatherModel*> m_dailyWeather;
};

#endif // WEEKWEATHERMODEL_H
