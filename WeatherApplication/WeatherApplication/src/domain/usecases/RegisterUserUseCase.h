#ifndef REGISTERUSERUSECASE_H
#define REGISTERUSERUSECASE_H

#include <functional>
#include <memory>

#include "../entities/AuthorizationReply.h"
#include "../entities/AuthorizationRequest.h"
#include "../interfaces/api/IUserRepository.h"

class RegisterUserUseCase
{
  public:
	explicit RegisterUserUseCase(IUserRepository *repo);
	QFuture<AuthorizationReply> execute(const AuthorizationRequest &request);

  private:
	IUserRepository *repository_;
};

#endif // REGISTERUSERUSECASE_H
