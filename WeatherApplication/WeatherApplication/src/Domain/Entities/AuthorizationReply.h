#ifndef AUTHORIZATIONREPLY_H
#define AUTHORIZATIONREPLY_H

#include <string>

struct AuthorizationReply
{
    static AuthorizationReply success() {
        return AuthorizationReply{true, ""};
    }
    static AuthorizationReply failure(const std::string& errorMessage) {
        return AuthorizationReply{false, errorMessage};
    }

    bool authorized = false;
    std::string messageError;
};

#endif // AUTHORIZATIONREPLY_H
