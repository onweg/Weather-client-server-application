#include "AuthViewModel.h"
#include <QDebug>
#include <future>
#include <QFutureWatcher>
#include <QFuture>
#include <QtConcurrent>
#include "../../Domain/Entities/AuthorizationRequest.h"



AuthViewModel::AuthViewModel(
        std::shared_ptr<AuthenticateUserUseCase> authUseCase,
        std::shared_ptr<RegisterUserUseCase> regUseCase, QObject *parent)
    : QObject(parent),
      authUseCase_(std::move(authUseCase)),
      regUseCase_(std::move(regUseCase))
{
}

void AuthViewModel::loginUser(const QString &username, const QString &password) {
    emit showLoadingAnimation();

    auto future = QtConcurrent::run([=]() -> AuthorizationReply {
        return authUseCase_->execute(AuthorizationRequest{username.toStdString(), password.toStdString()}).get();
    });

    auto* watcher = new QFutureWatcher<AuthorizationReply>(this);
    connect(watcher, &QFutureWatcher<AuthorizationReply>::finished, this, [this, watcher]() {
        const AuthorizationReply reply = watcher->result();
        emit hideLoadingAnimation();
        if (reply.success)
            emit authSucceeded();
        else
            emit authFailed(QString::fromStdString(reply.message));
        watcher->deleteLater();
    });

    watcher->setFuture(future);
}

void AuthViewModel::registerUser(const QString &username, const QString &password)
{
    emit showLoadingAnimation();

    auto future = QtConcurrent::run([=]() -> AuthorizationReply {
        return regUseCase_->execute(AuthorizationRequest{username.toStdString(), password.toStdString()}).get();
    });

    auto* watcher = new QFutureWatcher<AuthorizationReply>(this);
    connect(watcher, &QFutureWatcher<AuthorizationReply>::finished, this, [this, watcher]() {
        const AuthorizationReply reply = watcher->result();
        emit hideLoadingAnimation();
        if (reply.success)
            emit authSucceeded();
        else
            emit authFailed(QString::fromStdString(reply.message));
        watcher->deleteLater();
    });

    watcher->setFuture(future);
}
