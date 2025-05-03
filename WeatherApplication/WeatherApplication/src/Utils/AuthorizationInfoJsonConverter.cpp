#include "AuthorizationInfoJsonConverter.h"

AuthorizationInfoJsonConverter::AuthorizationInfoJsonConverter(QObject *parent) : QObject(parent)
{

}

QJsonObject AuthorizationInfoJsonConverter::loginUserToJsonObject(const User &user)
{
    QJsonObject obj;
    obj["command"] = "LOGIN";
    obj["login"] = QString::fromStdString(user.username);
    obj["password"] = QString::fromStdString(user.passwordHash);
    return obj;
}

QJsonObject AuthorizationInfoJsonConverter::registerUserToJsonObject(const User &user)
{
    QJsonObject obj;
    obj["command"] = "REGISTER";
    obj["login"] = QString::fromStdString(user.username);
    obj["password"] = QString::fromStdString(user.passwordHash);
    return obj;
}

QJsonDocument AuthorizationInfoJsonConverter::loginUserToJsonDocument(const User &user)
{
    QJsonDocument doc(loginUserToJsonObject(user));
    return doc;
}

QJsonDocument AuthorizationInfoJsonConverter::registerUserToJsonDocument(const User &user)
{
    QJsonDocument doc(registerUserToJsonObject(user));
    return doc;
}
