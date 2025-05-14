#ifndef IUSERREPOSITORY_H
#define IUSERREPOSITORY_H

#include "../../Entities/AuthorizationRequest.h"
#include "../../Entities/AuthorizationReply.h"
#include "../../Utils/Result.h"

#include <functional>

class IUserRepository {
public:
    virtual ~IUserRepository() = default;
    virtual AuthorizationReply findUser(const AuthorizationRequest& request) = 0;
    virtual AuthorizationReply registerUser(const AuthorizationRequest& request) = 0;
};

#endif // IUSERREPOSITORY_H
