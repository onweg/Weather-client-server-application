#include "AuthViewModel.h"
#include <QCryptographicHash>
#include <QDebug>
#include "../Mappers/UserModelMapper.h"
#include "../UIModels/UserModel.h"


AuthViewModel::AuthViewModel(std::shared_ptr<AuthenticateUserUseCase> authUseCase, std::shared_ptr<RegisterUserUseCase> regUseCase, QObject *parent)
    :QObject(parent), authUseCase_(std::move(authUseCase)), regUseCase_(std::move(regUseCase))
{
    user = new UserModel(this);
}

void AuthViewModel::loginUser(const QString &username, const QString &password){
    user->setUsername(username);
    user->setPassword(password);
    authUseCase_->execute(UserModelMapper::fromUiModel(user), [this](Result<User> result) {
        if (result.isSuccess()) {
            emit authSucceeded();
        } else {
            emit authFailed(QString::fromStdString(result.errorMessage()));
        }
    });
}

void AuthViewModel::registerUser(const QString &username, const QString &password)
{
    user->setUsername(username);
    user->setPassword(password);
    regUseCase_->execute(UserModelMapper::fromUiModel(user), [this](Result<User> result) {
        if (result.isSuccess()) {
            emit authSucceeded();
        } else {
            emit authFailed(QString::fromStdString(result.errorMessage()));
        }
    });
}

