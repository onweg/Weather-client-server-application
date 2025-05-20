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

private:
    static bool hasValidStatusField(const QJsonObject& obj);
    static bool hasValidMessageField(const QJsonObject& obj);
    static AuthorizationReply createReplyFromStatusAndMessage(const QString& status, const QString& message);

signals:

};

#endif // AUTHORIZATIONREPLYJSONCONVERTER_H
