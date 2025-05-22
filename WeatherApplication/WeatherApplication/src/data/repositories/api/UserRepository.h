#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include <QNetworkAccessManager>
#include <QObject>
#include <memory>

#include "../../../domain/interfaces/api/IUserRepository.h"
#include "../../../domain/interfaces/config/IConfigProvider.h"
#include "../../../domain/interfaces/sharedstate/ISharedState.h"

class UserRepository : public QObject, public IUserRepository
{
	Q_OBJECT

  public:
	UserRepository(std::shared_ptr<IConfigProvider> config,
	               std::shared_ptr<ISharedState> state,
	               QObject *parent = nullptr);
	QFuture<AuthorizationReply>
	findUser(const AuthorizationRequest &request) override;
	QFuture<AuthorizationReply>
	registerUser(const AuthorizationRequest &request) override;

  private:
	enum class AuthCommand
	{
		Login,
		Register
	};

	void initConfig();
	QFuture<AuthorizationReply>
	startAuthorization(const AuthorizationRequest &request,
	                   AuthCommand command);
	QByteArray buildRequestData(const AuthorizationRequest &request,
	                            AuthCommand command);
	QNetworkRequest buildHttpRequest();
	void sendHttpRequest(
	    const QNetworkRequest &req, const QByteArray &data,
	    const AuthorizationRequest &user,
	    std::shared_ptr<QFutureInterface<AuthorizationReply>> futureInterface,
	    AuthCommand command);
	AuthorizationReply parseReply(const QByteArray &response,
	                              const AuthorizationRequest &user);
	void handleReply(
	    QNetworkReply *reply, const AuthorizationRequest &user,
	    std::shared_ptr<QFutureInterface<AuthorizationReply>> futureInterface);

	std::shared_ptr<IConfigProvider> configProvider_;
	std::shared_ptr<ISharedState> sharedState_;
	std::shared_ptr<ServerHostConfig> serverHostConfig_;
	QNetworkAccessManager *networkManager_;
};

#endif // USERREPOSITORY_H
