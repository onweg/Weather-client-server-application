#ifndef AUTHENTICATEUSERUSECASE_H
#define AUTHENTICATEUSERUSECASE_H

#include <memory>
#include <functional>

#include "../Interfaces/Api/IUserRepository.h"
#include "../Entities/AuthorizationReply.h"
#include "../Entities/AuthorizationRequest.h"

class  AuthenticateUserUseCase {
public:
    explicit AuthenticateUserUseCase(IUserRepository* repo);
    // принимаем entity возвращаем entiry
    QFuture<AuthorizationReply> execute(const AuthorizationRequest& request);
private:
    IUserRepository* repository_;
};

#endif
