#include "AuthViewModel.h"
#include <QDebug>
#include <QFutureWatcher>

AuthViewModel::AuthViewModel(std::shared_ptr<AuthenticateUserUseCase> authUseCase, std::shared_ptr<RegisterUserUseCase> regUseCase, QObject *parent)
    :QObject(parent), authUseCase_(std::move(authUseCase)), regUseCase_(std::move(regUseCase))
{
}

void AuthViewModel::loginUser(const QString &username, const QString &password)
{
    executeAuthOperation(username, password, [this](const AuthorizationRequest& req) {
        return authUseCase_->execute(req);
    });
}

void AuthViewModel::registerUser(const QString &username, const QString &password)
{
    executeAuthOperation(username, password, [this](const AuthorizationRequest& req) {
        return regUseCase_->execute(req);
    });
}

void AuthViewModel::executeAuthOperation(const QString &username, const QString &password, AuthFunction authFunc)
{
    try {
        QFuture<AuthorizationReply> future = authFunc(AuthorizationRequest{username.toStdString(), password.toStdString()});
        auto* watcher = new QFutureWatcher<AuthorizationReply>(this);
        connect(watcher, &QFutureWatcher<AuthorizationReply>::finished, this, [this, watcher]() {
            const AuthorizationReply reply = watcher->result();
            if (reply.authorized) {
                emit authSucceeded();
            } else {
                emit authFailed(QString::fromStdString(reply.messageError));
            }
            watcher->deleteLater();
        });

        watcher->setFuture(future);
    }  catch (const std::runtime_error& error) {
        emit authFailed(QString::fromStdString(error.what()));
    }

}
