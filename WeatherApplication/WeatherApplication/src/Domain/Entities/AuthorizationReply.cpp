#include "AuthorizationReply.h"

AuthorizationReply::AuthorizationReply()
    : m_authorized(false)
{
}

AuthorizationReply::AuthorizationReply(bool authorized, const std::string& messageError)
    : m_authorized(authorized), m_messageError(messageError)
{
}

bool AuthorizationReply::isAuthorized() const
{
    return m_authorized;
}

void AuthorizationReply::setAuthorized(bool authorized)
{
    m_authorized = authorized;
}

const std::string& AuthorizationReply::getMessageError() const
{
    return m_messageError;
}

void AuthorizationReply::setMessageError(const std::string& messageError)
{
    m_messageError = messageError;
}

AuthorizationReply AuthorizationReply::success()
{
    return AuthorizationReply(true, "");
}

AuthorizationReply AuthorizationReply::failure(const std::string& errorMessage)
{
    return AuthorizationReply(false, errorMessage);
}
