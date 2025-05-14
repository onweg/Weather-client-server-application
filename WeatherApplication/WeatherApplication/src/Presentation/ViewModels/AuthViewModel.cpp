#include "AuthViewModel.h"
#include <QCryptographicHash>
#include <QDebug>
#include <future>
#include <QFutureWatcher>
#include <QFuture>
#include <QtConcurrent>
#include "../../Domain/Entities/AuthorizationRequest.h"



AuthViewModel::AuthViewModel(
        std::shared_ptr<AuthenticateUserUseCase> authUseCase,
        std::shared_ptr<RegisterUserUseCase> regUseCase, QObject *parent)
    :QObject(parent), authUseCase_(std::move(authUseCase)),
      regUseCase_(std::move(regUseCase))
{
}

void AuthViewModel::loginUser(const QString &username, const QString &password) {
    emit showLoadingAnimation();

    std::future<AuthorizationReply> future =
        authUseCase_->execute(AuthorizationRequest{username.toStdString(), password.toStdString()});

    auto *watcher = new QFutureWatcher<AuthorizationReply>(this);
    watcher->setFuture(std::move(future));

    connect(watcher, &QFutureWatcher<AuthorizationReply>::finished, this, [this, watcher]() {
        AuthorizationReply reply = watcher->result();
        emit hideLoadingAnimation();
        if (reply.success)
            emit authSucceeded();
        else
            emit authFailed(QString::fromStdString(reply.message));
        watcher->deleteLater();
    });
}

void AuthViewModel::registerUser(const QString &username, const QString &password)
{
    emit showLoadingAnimation();

    std::future<AuthorizationReply> future =
        regUseCase_->execute(AuthorizationRequest{username.toStdString(), password.toStdString()});

    auto *watcher = new QFutureWatcher<AuthorizationReply>(this);
    watcher->setFuture(std::move(future));

    connect(watcher, &QFutureWatcher<AuthorizationReply>::finished, this, [this, watcher]() {
        AuthorizationReply reply = watcher->result();
        emit hideLoadingAnimation();
        if (reply.success)
            emit authSucceeded();
        else
            emit authFailed(QString::fromStdString(reply.message));
        watcher->deleteLater();
    });
}

void AuthViewModel::runAsyncOperation(std::function<AuthorizationReply()> operation)
{
    emit showLoadingAnimation();

    auto *watcher = new QFutureWatcher<AuthorizationReply>(this);
    connect(watcher, &QFutureWatcher<AuthorizationReply>::finished, this, [this, watcher]() {
        const AuthorizationReply& reply = watcher->result();
        emit hideLoadingAnimation();
        if (reply.success) {
            emit authSucceeded();
        } else {
            emit authFailed(QString::fromStdString(reply.message));
        }
        watcher->deleteLater();
    });

    watcher->setFuture(QtConcurrent::run(operation));
}
