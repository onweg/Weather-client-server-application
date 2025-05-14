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

    static QJsonObject loginUserToJsonObject(const User &user);
    static QJsonObject registerUserToJsonObject(const User &user);
    static QJsonDocument loginUserToJsonDocument(const User &user);
    static QJsonDocument registerUserToJsonDocument(const User &user);


signals:

};

#endif // AUTHORIZATIONINFOJSONCONVERTER_H
