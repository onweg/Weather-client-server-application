#ifndef AUTHVIEWMODEL_H
#define AUTHVIEWMODEL_H

#include <QFuture>
#include <QObject>
#include <functional>
#include <memory>

#include "../../domain/usecases/AuthenticateUserUseCase.h"
#include "../../domain/usecases/RegisterUserUseCase.h"

using AuthFunction =
    std::function<QFuture<AuthorizationReply>(const AuthorizationRequest &)>;

class AuthViewModel : public QObject
{
	Q_OBJECT

  public:
	explicit AuthViewModel(std::shared_ptr<AuthenticateUserUseCase> authUseCase,
	                       std::shared_ptr<RegisterUserUseCase> regUseCase,
	                       QObject *parent = nullptr);

	Q_INVOKABLE void loginUser(const QString &username,
	                           const QString &password);
	Q_INVOKABLE void registerUser(const QString &username,
	                              const QString &password);

  signals:
	void authSucceeded();
	void authFailed(const QString &message);

  private:
	std::shared_ptr<AuthenticateUserUseCase> authUseCase_;
	std::shared_ptr<RegisterUserUseCase> regUseCase_;

	void executeAuthOperation(const QString &username, const QString &password,
	                          AuthFunction authFunc);
	void setupWatcherAndStart(QFuture<AuthorizationReply> future);
	void handleAuthResult(QFutureWatcher<AuthorizationReply> *watcher);
};

#endif // AUTHVIEWMODEL_H
