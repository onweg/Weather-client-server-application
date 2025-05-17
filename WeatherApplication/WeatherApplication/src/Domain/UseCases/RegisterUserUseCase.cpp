#include "RegisterUserUseCase.h"

RegisterUserUseCase::RegisterUserUseCase(IUserRepository *repo)
    :repository_(repo)
{

}

QFuture<AuthorizationReply> RegisterUserUseCase::execute(const AuthorizationRequest &request)
{
    return repository_->registerUser(request);
}
