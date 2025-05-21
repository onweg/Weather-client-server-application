#include "AuthorizationInfoJsonConverter.h"

AuthorizationInfoJsonConverter::AuthorizationInfoJsonConverter(QObject *parent) : QObject(parent)
{

}

QJsonObject AuthorizationInfoJsonConverter::loginUserToJsonObject(const AuthorizationRequestDto &request)
{
    return createRequestObject(request, "LOGIN");
}

QJsonObject AuthorizationInfoJsonConverter::registerUserToJsonObject(const AuthorizationRequestDto &request)
{
    return createRequestObject(request, "REGISTER");
}
QJsonDocument AuthorizationInfoJsonConverter::loginUserToJsonDocument(const AuthorizationRequestDto &request)
{
    QJsonDocument doc(loginUserToJsonObject(request));
    return doc;
}

QJsonDocument AuthorizationInfoJsonConverter::registerUserToJsonDocument(const AuthorizationRequestDto &request)
{
    QJsonDocument doc(registerUserToJsonObject(request));
    return doc;
}

QJsonObject AuthorizationInfoJsonConverter::createRequestObject(const AuthorizationRequestDto& request, const QString& command)
{
    QJsonObject obj;
    obj["command"] = command;
    obj["login"] = QString::fromStdString(request.username);
    obj["password"] = QString::fromStdString(request.passwordHash);
    return obj;
}
