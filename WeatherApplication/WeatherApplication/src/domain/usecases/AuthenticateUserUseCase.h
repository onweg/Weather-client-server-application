#ifndef AUTHENTICATEUSERUSECASE_H
#define AUTHENTICATEUSERUSECASE_H

#include <functional>
#include <memory>

#include "../entities/AuthorizationReply.h"
#include "../entities/AuthorizationRequest.h"
#include "../interfaces/api/IUserRepository.h"

class AuthenticateUserUseCase
{
  public:
	explicit AuthenticateUserUseCase(IUserRepository *repo);
	QFuture<AuthorizationReply> execute(const AuthorizationRequest &request);

  private:
	IUserRepository *repository_;
};

#endif
