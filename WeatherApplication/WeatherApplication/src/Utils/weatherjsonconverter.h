#ifndef WEATHERJSONCONVERTER_H
#define WEATHERJSONCONVERTER_H

#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include <QDateTime>
#include <QDateTime>
#include <QMap>

class WeatherJsonConverter : public QObject
{
    Q_OBJECT
public:
    explicit WeatherJsonConverter(QObject *parent = nullptr);
    static QJsonObject getCorrectData(QJsonObject jsonObj);

private:
    QJsonObject processWeatherData(const QJsonObject &originalJson);
    QJsonObject createDayData(const QJsonObject &forecast);

};

#endif // DATAEDITOR_H
