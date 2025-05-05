#include "AuthenticateUserUseCase.h"
#include <QDebug>

AuthenticateUserUseCase::AuthenticateUserUseCase(std::shared_ptr<IUserRepository> repo)
    : repository_(std::move(repo))
{

}

void AuthenticateUserUseCase::execute(const User &user, std::function<void (Result<User>)> callback)
{
    qDebug() << "AuthenticateUserUseCase::execute";
    repository_->findUser(user, [callback](Result<User> result){
        callback(result);
    });
}



