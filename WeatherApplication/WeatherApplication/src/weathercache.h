#ifndef WEATHERCACHE_H
#define WEATHERCACHE_H

// хранит временные данные о погоде в течении 15 минут
// помогает быстро доставать данные о погоде чтоб меньше отправлять API

#include <QObject>

class WeatherCache : public QObject
{
    Q_OBJECT
public:
    explicit WeatherCache(QObject *parent = nullptr);

signals:

};

#endif // WEATHERCACHE_H
