#include "RegisterUserUseCase.h"

RegisterUserUseCase::RegisterUserUseCase(IUserRepository *repo)
    :repository_(repo)
{

}

void RegisterUserUseCase::execute(const User &user, std::function<void (Result<User>)> callback)
{
    repository_->registerUser(user, [callback](Result<User> result){
        callback(result);
    });
}
