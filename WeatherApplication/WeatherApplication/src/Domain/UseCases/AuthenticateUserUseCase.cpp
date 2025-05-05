#include "AuthenticateUserUseCase.h"

AuthenticateUserUseCase::AuthenticateUserUseCase(IUserRepository* repo)
    : repository_(repo)
{

}

void AuthenticateUserUseCase::execute(const User &user, std::function<void (Result<User>)> callback)
{
    repository_->findUser(user, [callback](Result<User> result){
        callback(result);
    });
}



