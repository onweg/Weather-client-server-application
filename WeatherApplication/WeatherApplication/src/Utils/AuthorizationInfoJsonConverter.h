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

    static QJsonObject loginUserToJsonObject(const AuthorizationRequest &request);
    static QJsonObject registerUserToJsonObject(const AuthorizationRequest &request);
    static QJsonDocument loginUserToJsonDocument(const AuthorizationRequest &request);
    static QJsonDocument registerUserToJsonDocument(const AuthorizationRequest &request);

private:
    static QJsonObject createRequestObject(const AuthorizationRequest& request, const QString& command);

signals:

};

#endif // AUTHORIZATIONINFOJSONCONVERTER_H
