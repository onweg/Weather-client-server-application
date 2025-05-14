#include "RegisterUserUseCase.h"

RegisterUserUseCase::RegisterUserUseCase(IUserRepository *repo)
    :repository_(repo)
{

}

AuthorizationReply RegisterUserUseCase::execute(const AuthorizationRequest &request)
{
    return repository_->registerUser(request);
}
