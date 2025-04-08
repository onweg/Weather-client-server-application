#ifndef WEATHERMANAGER_H
#define WEATHERMANAGER_H

#include <QObject>
#include <QJsonObject>
#include <QDebug>

class WeatherManager : public QObject
{
    Q_OBJECT
public:
    explicit WeatherManager(QObject *parent = nullptr);

private:

public slots:
    void slotCityChange(const QString &city);
    void slotRecivedWeatherData(const QJsonObject &jsonObj);

private slots:

signals:
    void findCityData(const QString &city);
    void weatherData(const QJsonObject &jsonObj);

};

#endif // WEATHERMANAGER_H
