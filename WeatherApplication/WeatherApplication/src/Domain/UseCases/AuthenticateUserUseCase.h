#ifndef AUTHENTICATEUSERUSECASE_H
#define AUTHENTICATEUSERUSECASE_H

#include <functional>
#include <memory>

#include "../Entities/AuthorizationReply.h"
#include "../Entities/AuthorizationRequest.h"
#include "../Interfaces/Api/IUserRepository.h"

class AuthenticateUserUseCase
{
  public:
	explicit AuthenticateUserUseCase(IUserRepository *repo);
	QFuture<AuthorizationReply> execute(const AuthorizationRequest &request);

  private:
	IUserRepository *repository_;
};

#endif
