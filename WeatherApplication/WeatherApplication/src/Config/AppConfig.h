#ifndef APPCONFIG_H
#define APPCONFIG_H

#include <QString>
#include <QJsonObject>
#include "../Types/ApiConfig.h"
#include "../Types/ServerHostConfig.h"

class AppConfig
{
public:
    ServerHostConfig serverHostConfig;
    ApiConfig rawApiConfig;

    static bool fromJson(const QJsonObject& obj, AppConfig& config);
};

#endif // APPCONFIG_H
