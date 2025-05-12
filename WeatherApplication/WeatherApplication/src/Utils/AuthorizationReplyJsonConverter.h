#ifndef AUTHORIZATIONREPLYJSONCONVERTER_H
#define AUTHORIZATIONREPLYJSONCONVERTER_H

#include "../Domain/Entities/AuthorizationReply.h"
#include <QJsonObject>
#include <QObject>

class AuthorizationReplyJsonConverter {
public:
 explicit AuthorizationReplyJsonConverter();

 static AuthorizationReply parseAuthorizationReply(const QJsonObject &jsonObj);

signals:
};

#endif	// AUTHORIZATIONREPLYJSONCONVERTER_H
