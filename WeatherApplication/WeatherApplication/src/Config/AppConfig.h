#ifndef APPCONFIG_H
#define APPCONFIG_H

#include <QString>
#include <QJsonObject>
#include "../Models/ApiConfig.h"
#include "../Models/ServerHostConfig.h"

class AppConfig
{
public:
    ServerHostConfig serverHostConfig;
    ApiConfig rawApiConfig;

    static bool fromJson(const QJsonObject& obj, AppConfig& config);

private:
    static bool parseServerHostConfig(const QJsonObject& obj, ServerHostConfig& config);
    static bool parseApiConfig(const QJsonObject& obj, ApiConfig& config);
};

#endif // APPCONFIG_H
