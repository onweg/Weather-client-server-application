#ifndef AUTHORIZATIONREQUEST_H
#define AUTHORIZATIONREQUEST_H

#include <string>

class AuthorizationRequest
{
public:
    AuthorizationRequest();
    AuthorizationRequest(const std::string& username, const std::string& passwordHash);

    const std::string& getUsername() const;
    void setUsername(const std::string& username);

    const std::string& getPasswordHash() const;
    void setPasswordHash(const std::string& passwordHash);

private:
    std::string m_username;
    std::string m_passwordHash;
};

#endif // AUTHORIZATIONREQUEST_H
