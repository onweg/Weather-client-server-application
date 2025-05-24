#include "AuthorizationReplyJsonConverter.h"

AuthorizationReplyJsonConverter::AuthorizationReplyJsonConverter() {}

AuthorizationReplyDto AuthorizationReplyJsonConverter::parseAuthorizationReply(
    const QJsonObject &jsonObj)
{
    if (!hasValidStatusField(jsonObj)) {
		return AuthorizationReplyDto::failure(
		    "Missing or invalid 'status' field in JSON.");
	}
    if (!hasValidMessageField(jsonObj)) {
		return AuthorizationReplyDto::failure(
		    "Missing or invalid 'message' field in JSON.");
	}
	QString status = jsonObj["status"].toString();
	QString message = jsonObj["message"].toString();

	return createReplyFromStatusAndMessage(status, message);
}

bool AuthorizationReplyJsonConverter::hasValidStatusField(
    const QJsonObject &obj)
{
	return obj.contains("status") && obj["status"].isString();
}

bool AuthorizationReplyJsonConverter::hasValidMessageField(
    const QJsonObject &obj)
{
	return obj.contains("message") && obj["message"].isString();
}

AuthorizationReplyDto
AuthorizationReplyJsonConverter::createReplyFromStatusAndMessage(
    const QString &status, const QString &message)
{
    if (status == "success") {
		return AuthorizationReplyDto::success();
	}
    else if (status == "error") {
		return AuthorizationReplyDto::failure(message.toStdString());
	}
	return AuthorizationReplyDto::failure("Unknown status value: " +
	                                      status.toStdString());
}
