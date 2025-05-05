#include "AuthorizationReplyJsonConverter.h"

AuthorizationReplyJsonConverter::AuthorizationReplyJsonConverter()
{

}

AuthorizationReply AuthorizationReplyJsonConverter::parseAuthorizationReply(const QJsonObject &jsonObj) {
    AuthorizationReply reply;
    if (!jsonObj.contains("status") || !jsonObj["status"].isString()) {
        reply.success = false;
        reply.message = "Invalid JSON: no 'status' field or invalid type.";
        return reply;
    }
    QString status = jsonObj["status"].toString();
    if (status == "success") {
        reply.success = true;
    } else if (status == "error") {
        reply.success = false;
    } else {
        reply.success = false;
        reply.message = "Invalid JSON: unknown 'status' value.";
        return reply;
    }
    if (!jsonObj.contains("message") || !jsonObj["message"].isString()) {
        reply.success = false;
        reply.message = "Invalid JSON: no 'message' field or invalid type.";
        return reply;
    }

    reply.message = jsonObj["message"].toString().toStdString();

    return reply;
}
