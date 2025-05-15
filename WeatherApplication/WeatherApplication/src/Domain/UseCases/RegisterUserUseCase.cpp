#include "RegisterUserUseCase.h"

RegisterUserUseCase::RegisterUserUseCase(IUserRepository *repo)
    :repository_(repo)
{

}

QFuture<Result<User>> RegisterUserUseCase::execute(const User &user)
{
    return repository_->registerUser(user);
}
