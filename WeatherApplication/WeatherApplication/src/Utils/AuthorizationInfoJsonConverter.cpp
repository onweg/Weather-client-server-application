#include "AuthorizationInfoJsonConverter.h"

AuthorizationInfoJsonConverter::AuthorizationInfoJsonConverter(QObject *parent) : QObject(parent)
{

}

QJsonObject AuthorizationInfoJsonConverter::toJsonObject(const AuthorizationInfo &data)
{
    QJsonObject obj;
    obj["command"] = data.command;
    obj["login"] = data.login;
    obj["password"] = data.password;
    return obj;
}

QJsonDocument AuthorizationInfoJsonConverter::toJsonDocument(const AuthorizationInfo &data)
{
    QJsonDocument doc(toJsonObject(data));
    return doc;
}
