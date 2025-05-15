#include "AuthViewModel.h"
#include <QCryptographicHash>
#include <QDebug>
#include "../Mappers/UserModelMapper.h"
#include "../UIModels/UserModel.h"


AuthViewModel::AuthViewModel(std::shared_ptr<AuthenticateUserUseCase> authUseCase, std::shared_ptr<RegisterUserUseCase> regUseCase, QObject *parent)
    :QObject(parent), authUseCase_(std::move(authUseCase)), regUseCase_(std::move(regUseCase))
{
    user_ = new UserModel(this);
}

void AuthViewModel::loginUser(const QString &username, const QString &password){
    user_->setUsername(username);
    user_->setPassword(password);

    QFuture<Result<User>> future = authUseCase_->execute(UserModelMapper::fromUiModel(user_));

    QFutureWatcher<Result<User>>* watcher = new QFutureWatcher<Result<User>>(this);
    connect(watcher, &QFutureWatcher<Result<User>>::finished, this, [this, watcher]() {
        Result<User> result = watcher->result();
        if (result.isSuccess()) {
            emit authSucceeded();
        } else {
            emit authFailed(QString::fromStdString(result.errorMessage()));
        }
        watcher->deleteLater();
    });
    watcher->setFuture(future);
}

void AuthViewModel::registerUser(const QString &username, const QString &password) {
    user_->setUsername(username);
    user_->setPassword(password);

    QFuture<Result<User>> future = regUseCase_->execute(UserModelMapper::fromUiModel(user_));

    QFutureWatcher<Result<User>>* watcher = new QFutureWatcher<Result<User>>(this);
    connect(watcher, &QFutureWatcher<Result<User>>::finished, this, [this, watcher]() {
        Result<User> result = watcher->result();
        if (result.isSuccess()) {
            emit authSucceeded();
        } else {
            emit authFailed(QString::fromStdString(result.errorMessage()));
        }
        watcher->deleteLater();
    });
    watcher->setFuture(future);
}
