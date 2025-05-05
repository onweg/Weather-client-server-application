#include "AuthenticateUserUseCase.h"
#include <QDebug>

AuthenticateUserUseCase::AuthenticateUserUseCase(IUserRepository* repo)
    : repository_(repo)
{

}

void AuthenticateUserUseCase::execute(const User &user, std::function<void (Result<User>)> callback)
{
    qDebug() << "AuthenticateUserUseCase::execute";
    repository_->findUser(user, [callback](Result<User> result){
        callback(result);
    });
}



