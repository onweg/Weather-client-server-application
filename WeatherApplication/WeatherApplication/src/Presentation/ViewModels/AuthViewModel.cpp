#include "AuthViewModel.h"
#include <QCryptographicHash>
#include <QDebug>
#include "../Mappers/UserModelMapper.h"
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

void AuthViewModel::loginUser(const QString &username, const QString &password)
{
    runAsyncOperation([this, username, password]() -> AuthorizationReply {
        try {
            return authUseCase_->execute(AuthorizationRequest{username.toStdString(), password.toStdString()});
        } catch (const std::exception& e) { // тут нужно дорабоать обработку исключения
            return AuthorizationReply{false, e.what()};
        }
    });
}

void AuthViewModel::registerUser(const QString &username, const QString &password)
{
    runAsyncOperation([this, username, password]() -> AuthorizationReply {
        try {
            return regUseCase_->execute(AuthorizationRequest{username.toStdString(), password.toStdString()});
        } catch (const std::exception& e) { // тут нужно дорабоать обработку исключения
            return AuthorizationReply{false, e.what()};
        }
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
