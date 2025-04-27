#ifndef APIREPLY_H
#define APIREPLY_H

#include <QString>
#include "weekweatherdata.h"

struct ApiReply
{
    WeekWeatherData data;
    bool success = true;
    QString errorMessage;
};

#endif // APIREPLY_H
