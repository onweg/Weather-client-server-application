#include "UserRepository.h"

#include <QDebug>
#include <QFuture>
#include <QFutureInterface>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QString>
#include <QUrl>

#include "../../../Utils/AuthorizationInfoJsonConverter.h"
#include "../../../Utils/AuthorizationReplyJsonConverter.h"
#include "../../DtoModels/AuthorizationReplyDto.h"
#include "../../DtoModels/AuthorizationRequestDto.h"
#include "../../Mappers/AuthorizationReplyDomainMapper.h"
#include "../../Mappers/AuthorizationRequestDomainMapper.h"

UserRepository::UserRepository(std::shared_ptr<IConfigProvider> config,
                               std::shared_ptr<ISharedState> state,
                               QObject *parent)
 : QObject(parent), configProvider_(std::move(config)),
   sharedState_(std::move(state))
{
	networkManager_ = new QNetworkAccessManager(this);
}

QFuture<AuthorizationReply>
UserRepository::findUser(const AuthorizationRequest &request)
{
	initConfig();
	return startAuthorization(request, AuthCommand::Login);
}

QFuture<AuthorizationReply>
UserRepository::registerUser(const AuthorizationRequest &request)
{
	initConfig();
	return startAuthorization(request, AuthCommand::Register);
}

void UserRepository::initConfig()
{
	if (!serverHostConfig_)
	{
		auto result = configProvider_->getServerHostConfig();
		if (!result.isSuccess())
		{
			throw std::runtime_error(result.errorMessage());
		}
		serverHostConfig_ = std::make_shared<ServerHostConfig>();
		*serverHostConfig_ = result.value();
	}
}

QFuture<AuthorizationReply>
UserRepository::startAuthorization(const AuthorizationRequest &request,
                                   AuthCommand command)
{
	auto futureInterface =
	    std::make_shared<QFutureInterface<AuthorizationReply>>();
	futureInterface->reportStarted();
	QByteArray data = buildRequestData(request, command);
	QNetworkRequest req = buildHttpRequest();
	sendHttpRequest(req, data, request, futureInterface, command);
	return futureInterface->future();
}

QByteArray UserRepository::buildRequestData(const AuthorizationRequest &request,
                                            AuthCommand command)
{
	if (command == AuthCommand::Login)
	{
		AuthorizationRequestDto dto =
		    AuthorizationRequestDomainMapper::toDto(request);
		auto jsonDoc =
		    AuthorizationInfoJsonConverter::loginUserToJsonDocument(dto);
		return jsonDoc.toJson();
	}
	else
	{
		AuthorizationRequestDto dto =
		    AuthorizationRequestDomainMapper::toDto(request);
		auto jsonDoc =
		    AuthorizationInfoJsonConverter::registerUserToJsonDocument(dto);
		return jsonDoc.toJson();
	}
}

QNetworkRequest UserRepository::buildHttpRequest()
{
	QString urlStr = "http://" +
	                 QString::fromStdString(serverHostConfig_->getIp()) + ":" +
	                 QString::fromStdString(serverHostConfig_->getPort());
	QUrl url(urlStr);
	QNetworkRequest req(url);
	req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
	return req;
}

void UserRepository::sendHttpRequest(
    const QNetworkRequest &req, const QByteArray &data,
    const AuthorizationRequest &user,
    std::shared_ptr<QFutureInterface<AuthorizationReply>> futureInterface,
    AuthCommand /*command*/)
{
	QNetworkReply *reply = networkManager_->post(req, data);
	QObject::connect(reply, &QNetworkReply::finished, this,
	                 [this, reply, user, futureInterface]()
	                 { handleReply(reply, user, futureInterface); });
}

void UserRepository::handleReply(
    QNetworkReply *reply, const AuthorizationRequest &user,
    std::shared_ptr<QFutureInterface<AuthorizationReply>> futureInterface)
{
	QByteArray response = reply->readAll();
	AuthorizationReply result = parseReply(response, user);
	futureInterface->reportResult(result);
	futureInterface->reportFinished();
	reply->deleteLater();
}

AuthorizationReply UserRepository::parseReply(const QByteArray &response,
                                              const AuthorizationRequest &user)
{
	QJsonParseError error;
	QJsonDocument doc = QJsonDocument::fromJson(response, &error);
	if (error.error != QJsonParseError::NoError)
	{
		return AuthorizationReply::failure("Ошибка парсинга JSON: " +
		                                   error.errorString().toStdString());
	}
	if (!doc.isObject())
	{
		return AuthorizationReply::failure("JSON не является объектом");
	}
	AuthorizationReplyDto dto =
	    AuthorizationReplyJsonConverter::parseAuthorizationReply(doc.object());
	AuthorizationReply result = AuthorizationReplyDomainMapper::fromDto(dto);
	if (result.isAuthorized())
	{
		sharedState_->setUsername(user.getUsername());
	}
	return result;
}
