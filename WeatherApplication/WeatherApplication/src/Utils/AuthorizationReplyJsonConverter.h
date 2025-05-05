#ifndef AUTHORIZATIONREPLYJSONCONVERTER_H
#define AUTHORIZATIONREPLYJSONCONVERTER_H

#include <QObject>
#include <QJsonObject>
#include "../Domain/Entities/AuthorizationReply.h"

class AuthorizationReplyJsonConverter
{
public:
    explicit AuthorizationReplyJsonConverter();

    static AuthorizationReply parseAuthorizationReply(const QJsonObject &jsonObj);

signals:

};

#endif // AUTHORIZATIONREPLYJSONCONVERTER_H
