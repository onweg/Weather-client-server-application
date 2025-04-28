#ifndef WEATHERUPDATER_H
#define WEATHERUPDATER_H

#include <QObject>
#include <QTimer>

#define SEC 3600

class WeatherUpdater : public QObject
{
    Q_OBJECT
public:
    explicit WeatherUpdater(QObject *parent = nullptr);
    void start();
    void resetTimer();

private:
    QTimer *timer_;

signals:
    void updateWeatherData();

};

#endif // WEATHERUPDATER_H
