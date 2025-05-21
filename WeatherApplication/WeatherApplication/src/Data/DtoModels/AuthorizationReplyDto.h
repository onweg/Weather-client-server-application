#ifndef AUTHORIZATIONREPLYDTO_H
#define AUTHORIZATIONREPLYDTO_H

#include <string>

struct AuthorizationReplyDto
{
    static AuthorizationReplyDto success() { return {true, ""}; }
    static AuthorizationReplyDto failure(const std::string& errorMessage) { return {false, errorMessage}; }

    bool authorized;
    std::string messageError;
};

#endif // AUTHORIZATIONREPLYDTO_H
