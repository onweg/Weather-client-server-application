#ifndef AUTHORIZATIONREPLYJSONCONVERTER_H
#define AUTHORIZATIONREPLYJSONCONVERTER_H

#include <QJsonObject>
#include <QObject>

#include "../data/dtomodels/AuthorizationReplyDto.h"

class AuthorizationReplyJsonConverter
{
  public:
	explicit AuthorizationReplyJsonConverter();

	static AuthorizationReplyDto
	parseAuthorizationReply(const QJsonObject &jsonObj);

  private:
	static bool hasValidStatusField(const QJsonObject &obj);
	static bool hasValidMessageField(const QJsonObject &obj);
	static AuthorizationReplyDto
	createReplyFromStatusAndMessage(const QString &status,
	                                const QString &message);
};

#endif // AUTHORIZATIONREPLYJSONCONVERTER_H
