#ifndef AUTHORIZATIONREQUEST_H
#define AUTHORIZATIONREQUEST_H

#include <string>

class AuthorizationRequest
{
private:
    std::string m_username;
    std::string m_passwordHash;

public:
    const std::string& getUsername() const;
    void setUsername(const std::string& username);

    const std::string& getPasswordHash() const;
    void setPasswordHash(const std::string& passwordHash);
};

#endif // AUTHORIZATIONREQUEST_H
