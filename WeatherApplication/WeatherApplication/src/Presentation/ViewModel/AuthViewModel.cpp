#include "AuthViewModel.h"
#include <QCryptographicHash>
#include <QDebug>
#include "../../Data/Mappers/UserMapper.h"
#include "../../Data/DtoModels/UserDto.h"


AuthViewModel::AuthViewModel(std::shared_ptr<AuthenticateUserUseCase> authUseCase, std::shared_ptr<RegisterUserUseCase> regUseCase, QObject *parent)
    :QObject(parent), authUseCase_(std::move(authUseCase)), regUseCase_(std::move(regUseCase))
{

}

void AuthViewModel::loginUser(const QString &username, const QString &password)
{
    user = UserDto(username, password);
    authUseCase_->execute(UserMapper::fromDro(user), [this](Result<User> result) {
        if (result.isSuccess()) {
            emit authSucceeded();
        } else {
            emit authFailed(QString::fromStdString(result.errorMessage()));
        }
    });
}

void AuthViewModel::registerUser(const QString &username, const QString &password)
{
    user = UserDto(username, password);
    regUseCase_->execute(UserMapper::fromDro(user), [this](Result<User> result) {
        if (result.isSuccess()) {
            emit authSucceeded();
        } else {
            emit authFailed(QString::fromStdString(result.errorMessage()));
        }
    });
}

