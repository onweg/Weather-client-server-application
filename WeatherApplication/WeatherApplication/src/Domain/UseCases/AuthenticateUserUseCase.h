#ifndef AUTHENTICATEUSERUSECASE_H
#define AUTHENTICATEUSERUSECASE_H

#include <functional>
#include <memory>

#include "../Entities/User.h"
#include "../Interfaces/Api/IUserRepository.h"
#include "../Utils/Result.h"

class AuthenticateUserUseCase {
  public:
    explicit AuthenticateUserUseCase(IUserRepository *repo);
    void execute(const User &user, std::function<void(Result<User>)> callback);

  private:
    IUserRepository *repository_;
};

#endif
