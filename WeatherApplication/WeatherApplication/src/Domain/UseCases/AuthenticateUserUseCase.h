#ifndef AUTHENTICATEUSERUSECASE_H
#define AUTHENTICATEUSERUSECASE_H

#include <memory>
#include <future>

#include "../Interfaces/Api/IUserRepository.h"
#include "../Entities/AuthorizationRequest.h"
#include "../Entities/AuthorizationReply.h"

class  AuthenticateUserUseCase {
public:
    explicit AuthenticateUserUseCase(IUserRepository* repo);
    AuthorizationReply execute(const AuthorizationRequest& request);
private:
    IUserRepository* repository_;
};

#endif
