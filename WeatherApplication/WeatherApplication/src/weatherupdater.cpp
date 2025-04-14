#include "weatherupdater.h"

WeatherUpdater::WeatherUpdater(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &WeatherUpdater::updateWeatherData);
}

void WeatherUpdater::start()
{
    if (!timer->isActive()) {
        timer->start(SEC * 1000);
    }
}

void WeatherUpdater::resetTimer()
{
    if (timer->isActive()) {
        timer->stop();
    }
    timer->start(SEC * 1000);
}
