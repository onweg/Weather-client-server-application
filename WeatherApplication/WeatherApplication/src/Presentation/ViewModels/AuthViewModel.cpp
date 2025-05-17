#include "AuthViewModel.h"
#include <QDebug>
#include <QFutureWatcher>

#include "../../Domain/Entities/AuthorizationRequest.h"
#include "../../Domain/Entities/AuthorizationReply.h"


AuthViewModel::AuthViewModel(std::shared_ptr<AuthenticateUserUseCase> authUseCase, std::shared_ptr<RegisterUserUseCase> regUseCase, QObject *parent)
    :QObject(parent), authUseCase_(std::move(authUseCase)), regUseCase_(std::move(regUseCase))
{
}

void AuthViewModel::loginUser(const QString &username, const QString &password){

    QFuture<AuthorizationReply> future = authUseCase_->execute(AuthorizationRequest{username.toStdString(), password.toStdString()});

    auto* watcher = new QFutureWatcher<AuthorizationReply>(this);
    connect(watcher, &QFutureWatcher<AuthorizationReply>::finished, this, [this, watcher]() {
        AuthorizationReply reply = watcher->result();
        if (reply.authorized) {
            emit authSucceeded();
        } else {
            emit authFailed(QString::fromStdString(reply.messageError));
        }
        watcher->deleteLater();
    });
    watcher->setFuture(future);
}

void AuthViewModel::registerUser(const QString &username, const QString &password) {

    QFuture<AuthorizationReply> future = regUseCase_->execute(AuthorizationRequest{username.toStdString(), password.toStdString()});

    auto* watcher = new QFutureWatcher<AuthorizationReply>(this);
    connect(watcher, &QFutureWatcher<AuthorizationReply>::finished, this, [this, watcher]() {
        AuthorizationReply reply = watcher->result();
        if (reply.authorized) {
            emit authSucceeded();
        } else {
            emit authFailed(QString::fromStdString(reply.messageError));
        }
        watcher->deleteLater();
    });
    watcher->setFuture(future);
}
