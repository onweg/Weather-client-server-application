#ifndef AUTHORIZATIONREPLY_H
#define AUTHORIZATIONREPLY_H

#include <string>

class AuthorizationReply
{
private:
    bool m_authorized;
    std::string m_messageError;

public:
    AuthorizationReply();

    AuthorizationReply(bool authorized, const std::string& messageError);

    bool isAuthorized() const;
    void setAuthorized(bool authorized);

    const std::string& getMessageError() const;
    void setMessageError(const std::string& messageError);

    static AuthorizationReply success();
    static AuthorizationReply failure(const std::string& errorMessage);
};

#endif // AUTHORIZATIONREPLY_H
