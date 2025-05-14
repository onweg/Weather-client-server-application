#ifndef AUTHORIZATIONINFOJSONCONVERTER_H
#define AUTHORIZATIONINFOJSONCONVERTER_H

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include "../Domain/Entities/AuthorizationRequest.h"

class AuthorizationInfoJsonConverter : public QObject
{
    Q_OBJECT
public:
    explicit AuthorizationInfoJsonConverter(QObject *parent = nullptr);

    static QJsonObject loginUserToJsonObject(const AuthorizationRequest &user);
    static QJsonObject registerUserToJsonObject(const AuthorizationRequest &user);
    static QJsonDocument loginUserToJsonDocument(const AuthorizationRequest &user);
    static QJsonDocument registerUserToJsonDocument(const AuthorizationRequest &user);


signals:

};

#endif // AUTHORIZATIONINFOJSONCONVERTER_H
