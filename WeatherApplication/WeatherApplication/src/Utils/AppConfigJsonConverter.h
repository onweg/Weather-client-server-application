#ifndef APPCONFIGJSONCONVERTER_H
#define APPCONFIGJSONCONVERTER_H

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include "../Data/DtoModels/AppConfigDto.h"

class AppConfigJsonConverter
{
public:
    explicit AppConfigJsonConverter();
    static bool fromJson(const QJsonObject& jsonObject, AppConfigDto& config);

private:
    static bool parseServerHostConfig(const QJsonObject& jsonObject, ServerHostConfigDto& config);
    static bool parseApiConfig(const QJsonObject& jsonObject, ApiConfigDto& config);
    static QJsonObject getJsonObject(const QJsonObject& obj, const QString& key);
    static std::string getStringValue(const QJsonObject& obj, const QString& key);
};

#endif // APPCONFIGJSONCONVERTER_H
