#include "AuthenticateUserUseCase.h"

AuthenticateUserUseCase::AuthenticateUserUseCase(IUserRepository* repo)
    : repository_(repo)
{

}

QFuture<Result<User>> AuthenticateUserUseCase::execute(const User &user)
{
    return repository_->findUser(user);
}



