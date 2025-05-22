#ifndef REGISTERUSERUSECASE_H
#define REGISTERUSERUSECASE_H

#include <functional>
#include <memory>

#include "../Entities/AuthorizationReply.h"
#include "../Entities/AuthorizationRequest.h"
#include "../Interfaces/Api/IUserRepository.h"

class RegisterUserUseCase
{
  public:
	explicit RegisterUserUseCase(IUserRepository *repo);
	QFuture<AuthorizationReply> execute(const AuthorizationRequest &request);

  private:
	IUserRepository *repository_;
};

#endif // REGISTERUSERUSECASE_H
