#include "WeatherUpdater.h"

WeatherUpdater::WeatherUpdater(QObject *parent) : QObject(parent)
{
    timer_ = new QTimer(this);
    connect(timer_, &QTimer::timeout, this, &WeatherUpdater::updateWeatherData);
}

void WeatherUpdater::start()
{
    if (!timer_->isActive()) {
        timer_->start(SEC * 1000);
    }
}

void WeatherUpdater::resetTimer()
{
    if (timer_->isActive()) {
        timer_->stop();
    }
    timer_->start(SEC * 1000);
}
