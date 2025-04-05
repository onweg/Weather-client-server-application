#ifndef WEATHERMANAGER_H
#define WEATHERMANAGER_H

#include <QObject>
#include "weatherapiclient.h"

class WeatherManager : public QObject
{
    Q_OBJECT
public:
    explicit WeatherManager(QObject *parent = nullptr);

private:
    WeatherApiClient wac;

signals:

};

#endif // WEATHERMANAGER_H
