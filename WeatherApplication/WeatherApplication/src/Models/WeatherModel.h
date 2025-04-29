#ifndef WEATHERMODEL_H
#define WEATHERMODEL_H

#include <QObject>
#include <QString>
#include <QDate>
#include "../Types/WeatherData.h"

class WeatherModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString city READ getCity CONSTANT)
    Q_PROPERTY(QString date READ getDate CONSTANT)
    Q_PROPERTY(QString description READ getDescription CONSTANT)
    Q_PROPERTY(double temp READ getTemp CONSTANT)
    Q_PROPERTY(double feelsLike READ getFeelsLike CONSTANT)
    Q_PROPERTY(double tempMax READ getTempMax CONSTANT)
    Q_PROPERTY(double tempMin READ getTempMin CONSTANT)
    Q_PROPERTY(double windSpeed READ getWindSpeed CONSTANT)
    Q_PROPERTY(int humidity READ getHumidity CONSTANT)
    Q_PROPERTY(int pressure READ getPressure CONSTANT)
    Q_PROPERTY(QString messageError READ getMessageError CONSTANT)

public:
    explicit WeatherModel(QObject *parent = nullptr);
    explicit WeatherModel(const WeatherData &data, QObject *parent = nullptr);

    void setData(const WeatherData &data);
    const WeatherData& getData() const;

    QString getCity() const;
    QString getDate() const;
    QString getDescription() const;
    double getTemp() const;
    double getFeelsLike() const;
    double getTempMax() const;
    double getTempMin() const;
    double getWindSpeed() const;
    int getHumidity() const;
    int getPressure() const;
    QString getMessageError() const;

private:
    WeatherData m_data;
};

Q_DECLARE_METATYPE(WeatherModel*)

#endif // WEATHERMODEL_H
