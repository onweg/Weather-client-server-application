#ifndef APIREPLY_H
#define APIREPLY_H

#include <QString>
#include "weekweatherdata.h"
#include <QJsonObject>

struct ApiReply
{
    QJsonObject data;
    bool success = true;
    QString messageError;
};

#endif // APIREPLY_H
