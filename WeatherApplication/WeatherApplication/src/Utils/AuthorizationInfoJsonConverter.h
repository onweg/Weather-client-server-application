#ifndef AUTHORIZATIONINFOJSONCONVERTER_H
#define AUTHORIZATIONINFOJSONCONVERTER_H

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include "../Models/AuthorizationInfo.h"

class AuthorizationInfoJsonConverter : public QObject
{
    Q_OBJECT
public:
    explicit AuthorizationInfoJsonConverter(QObject *parent = nullptr);

    static QJsonObject toJsonObject(const AuthorizationInfo &data);
    static QJsonDocument toJsonDocument(const AuthorizationInfo &data);

signals:

};

#endif // AUTHORIZATIONINFOJSONCONVERTER_H
