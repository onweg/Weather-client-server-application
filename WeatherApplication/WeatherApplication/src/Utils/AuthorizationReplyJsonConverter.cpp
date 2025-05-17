#include "AuthorizationReplyJsonConverter.h"

AuthorizationReplyJsonConverter::AuthorizationReplyJsonConverter()
{

}

AuthorizationReply AuthorizationReplyJsonConverter::parseAuthorizationReply(const QJsonObject &jsonObj)
{
    if (!jsonObj.contains("status") || !jsonObj["status"].isString()) {
        return AuthorizationReply::failure("Missing or invalid 'status' field in JSON.");
    }

    QString status = jsonObj["status"].toString();

    if (!jsonObj.contains("message") || !jsonObj["message"].isString()) {
        return AuthorizationReply::failure("Missing or invalid 'message' field in JSON.");
    }

    QString message = jsonObj["message"].toString();

    if (status == "success") {
        return AuthorizationReply::success();
    } else if (status == "error") {
        return AuthorizationReply::failure(message.toStdString());
    } else {
        return AuthorizationReply::failure("Unknown status value: " + status.toStdString());
    }
}
