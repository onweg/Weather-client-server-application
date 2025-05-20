#include "AuthorizationReplyJsonConverter.h"

AuthorizationReplyJsonConverter::AuthorizationReplyJsonConverter()
{

}

AuthorizationReply AuthorizationReplyJsonConverter::parseAuthorizationReply(const QJsonObject &jsonObj)
{
    if (!hasValidStatusField(jsonObj)) {
        return AuthorizationReply::failure("Missing or invalid 'status' field in JSON.");
    }
    if (!hasValidMessageField(jsonObj)) {
        return AuthorizationReply::failure("Missing or invalid 'message' field in JSON.");
    }
    QString status = jsonObj["status"].toString();
    QString message = jsonObj["message"].toString();

    return createReplyFromStatusAndMessage(status, message);
}

bool AuthorizationReplyJsonConverter::hasValidStatusField(const QJsonObject& obj)
{
    return obj.contains("status") && obj["status"].isString();
}

bool AuthorizationReplyJsonConverter::hasValidMessageField(const QJsonObject& obj)
{
    return obj.contains("message") && obj["message"].isString();
}

AuthorizationReply AuthorizationReplyJsonConverter::createReplyFromStatusAndMessage(
    const QString& status, const QString& message)
{
    if (status == "success") {
        return AuthorizationReply::success();
    } else if (status == "error") {
        return AuthorizationReply::failure(message.toStdString());
    }
    return AuthorizationReply::failure("Unknown status value: " + status.toStdString());
}
