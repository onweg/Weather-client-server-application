#ifndef AUTHORIZATIONREPLYJSONCONVERTER_H
#define AUTHORIZATIONREPLYJSONCONVERTER_H

#include <QObject>
#include <QJsonObject>
#include "../Types/AuthorizationReply.h"

class AuthorizationReplyJsonConverter : public QObject
{
    Q_OBJECT
public:
    explicit AuthorizationReplyJsonConverter(QObject *parent = nullptr);

    static AuthorizationReply parseAuthorizationReply(const QJsonObject &jsonObj);

signals:

};

#endif // AUTHORIZATIONREPLYJSONCONVERTER_H
