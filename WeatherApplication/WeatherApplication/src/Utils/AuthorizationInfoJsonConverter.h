#ifndef AUTHORIZATIONINFOJSONCONVERTER_H
#define AUTHORIZATIONINFOJSONCONVERTER_H

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include "../Data/DtoModels/AuthorizationRequestDto.h"
class AuthorizationInfoJsonConverter : public QObject
{
    Q_OBJECT
public:
    explicit AuthorizationInfoJsonConverter(QObject *parent = nullptr);

    static QJsonObject loginUserToJsonObject(const AuthorizationRequestDto &request);
    static QJsonObject registerUserToJsonObject(const AuthorizationRequestDto &request);
    static QJsonDocument loginUserToJsonDocument(const AuthorizationRequestDto &request);
    static QJsonDocument registerUserToJsonDocument(const AuthorizationRequestDto &request);

private:
    static QJsonObject createRequestObject(const AuthorizationRequestDto& request, const QString& command);

signals:

};

#endif // AUTHORIZATIONINFOJSONCONVERTER_H
