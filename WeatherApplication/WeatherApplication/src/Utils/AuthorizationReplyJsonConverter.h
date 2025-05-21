#ifndef AUTHORIZATIONREPLYJSONCONVERTER_H
#define AUTHORIZATIONREPLYJSONCONVERTER_H

#include <QObject>
#include <QJsonObject>
#include "../Data/DtoModels/AuthorizationReplyDto.h"

class AuthorizationReplyJsonConverter
{
public:
    explicit AuthorizationReplyJsonConverter();

    static AuthorizationReplyDto parseAuthorizationReply(const QJsonObject &jsonObj);

private:
    static bool hasValidStatusField(const QJsonObject& obj);
    static bool hasValidMessageField(const QJsonObject& obj);
    static AuthorizationReplyDto createReplyFromStatusAndMessage(const QString& status, const QString& message);

signals:

};

#endif // AUTHORIZATIONREPLYJSONCONVERTER_H
