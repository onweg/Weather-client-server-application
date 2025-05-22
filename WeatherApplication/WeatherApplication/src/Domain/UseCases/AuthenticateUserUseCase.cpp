#include "AuthenticateUserUseCase.h"

AuthenticateUserUseCase::AuthenticateUserUseCase(IUserRepository *repo)
 : repository_(repo)
{
}

QFuture<AuthorizationReply>
AuthenticateUserUseCase::execute(const AuthorizationRequest &request)
{
	return repository_->findUser(request);
}
