#ifndef APPCONFIGJSONCONVERTER_H
#define APPCONFIGJSONCONVERTER_H

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include "../Models/AppConfig.h"
#include "../Models/ApiConfig.h"
#include "../Models/ServerHostConfig.h"

class AppConfigJsonConverter : public QObject
{
    Q_OBJECT
public:
    explicit AppConfigJsonConverter(QObject *parent = nullptr);
    static bool fromJson(const QJsonObject& jsonObject, AppConfig& config);

private:
    static bool parseServerHostConfig(const QJsonObject& jsonObject, ServerHostConfig& config);
    static bool parseApiConfig(const QJsonObject& jsonObject, ApiConfig& config);
};

#endif // APPCONFIGJSONCONVERTER_H