#include "AuthorizationRequest.h"

AuthorizationRequest::AuthorizationRequest()
    : m_username(""), m_passwordHash("")
{
}

AuthorizationRequest::AuthorizationRequest(const std::string& username, const std::string& passwordHash)
    : m_username(username), m_passwordHash(passwordHash)
{
}

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
