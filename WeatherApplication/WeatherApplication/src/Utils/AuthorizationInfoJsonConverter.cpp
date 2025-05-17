#include "AuthorizationInfoJsonConverter.h"

AuthorizationInfoJsonConverter::AuthorizationInfoJsonConverter(QObject *parent) : QObject(parent)
{

}

QJsonObject AuthorizationInfoJsonConverter::loginUserToJsonObject(const AuthorizationRequest &request)
{
    QJsonObject obj;
    obj["command"] = "LOGIN";
    obj["login"] = QString::fromStdString(request.username);
    obj["password"] = QString::fromStdString(request.passwordHash);
    return obj;
}

QJsonObject AuthorizationInfoJsonConverter::registerUserToJsonObject(const AuthorizationRequest &request)
{
    QJsonObject obj;
    obj["command"] = "REGISTER";
    obj["login"] = QString::fromStdString(request.username);
    obj["password"] = QString::fromStdString(request.passwordHash);
    return obj;
}

QJsonDocument AuthorizationInfoJsonConverter::loginUserToJsonDocument(const AuthorizationRequest &request)
{
    QJsonDocument doc(loginUserToJsonObject(request));
    return doc;
}

QJsonDocument AuthorizationInfoJsonConverter::registerUserToJsonDocument(const AuthorizationRequest &request)
{
    QJsonDocument doc(registerUserToJsonObject(request));
    return doc;
}
