#include "RegisterUserUseCase.h"

RegisterUserUseCase::RegisterUserUseCase(IUserRepository *repo)
    :repository_(repo)
{

}

std::future<AuthorizationReply> RegisterUserUseCase::execute(const AuthorizationRequest &request)
{
    return repository_->registerUser(request);
}
