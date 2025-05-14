#include "AuthenticateUserUseCase.h"

AuthenticateUserUseCase::AuthenticateUserUseCase(IUserRepository* repo)
    : repository_(repo)
{

}

std::future<AuthorizationReply> AuthenticateUserUseCase::execute(const AuthorizationRequest &request)
{
    return repository_->findUser(request);
}



