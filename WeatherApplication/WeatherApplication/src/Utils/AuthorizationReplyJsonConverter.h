#ifndef AUTHORIZATIONREPLYJSONCONVERTER_H
#define AUTHORIZATIONREPLYJSONCONVERTER_H

#include <QJsonObject>
#include <QObject>

#include "../Domain/Entities/AuthorizationReply.h"

class AuthorizationReplyJsonConverter {
  public:
    explicit AuthorizationReplyJsonConverter();

    static AuthorizationReply parseAuthorizationReply(
        const QJsonObject &jsonObj);

  signals:
};

#endif // AUTHORIZATIONREPLYJSONCONVERTER_H
