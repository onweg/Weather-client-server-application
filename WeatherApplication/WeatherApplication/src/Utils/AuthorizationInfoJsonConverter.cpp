#include "AuthorizationInfoJsonConverter.h"

AuthorizationInfoJsonConverter::AuthorizationInfoJsonConverter(QObject *parent) : QObject(parent)
{

}

QJsonObject AuthorizationInfoJsonConverter::loginUserToJsonObject(const AuthorizationRequest &request)
{
    return createRequestObject(request, "LOGIN");
}

QJsonObject AuthorizationInfoJsonConverter::registerUserToJsonObject(const AuthorizationRequest &request)
{
    return createRequestObject(request, "REGISTER");
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

QJsonObject AuthorizationInfoJsonConverter::createRequestObject(const AuthorizationRequest& request, const QString& command)
{
    QJsonObject obj;
    obj["command"] = command;
    obj["login"] = QString::fromStdString(request.username);
    obj["password"] = QString::fromStdString(request.passwordHash);
    return obj;
}
