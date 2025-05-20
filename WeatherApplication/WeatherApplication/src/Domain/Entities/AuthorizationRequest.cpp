#include "AuthorizationRequest.h"

const std::string& AuthorizationRequest::getUsername() const
{
    return m_username;
}

void AuthorizationRequest::setUsername(const std::string& username)
{
    m_username = username;
}

const std::string& AuthorizationRequest::getPasswordHash() const
{
    return m_passwordHash;
}

void AuthorizationRequest::setPasswordHash(const std::string& passwordHash)
{
    m_passwordHash = passwordHash;
}
