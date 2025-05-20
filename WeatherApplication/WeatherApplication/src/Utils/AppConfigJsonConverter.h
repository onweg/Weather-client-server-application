#ifndef APPCONFIGJSONCONVERTER_H
#define APPCONFIGJSONCONVERTER_H

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include "../Domain/Entities/AppConfig.h"
#include "../Domain/Entities/ApiConfig.h"
#include "../Domain/Entities/ServerHostConfig.h"

class AppConfigJsonConverter
{
public:
    explicit AppConfigJsonConverter();
    static bool fromJson(const QJsonObject& jsonObject, AppConfig& config);

private:
    static bool parseServerHostConfig(const QJsonObject& jsonObject, ServerHostConfig& config);
    static bool parseApiConfig(const QJsonObject& jsonObject, ApiConfig& config);
    static QJsonObject getJsonObject(const QJsonObject& obj, const QString& key);
    static std::string getStringValue(const QJsonObject& obj, const QString& key);
};

#endif // APPCONFIGJSONCONVERTER_H
