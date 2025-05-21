#include "AuthorizationReplyDomainMapper.h"

AuthorizationReplyDto AuthorizationReplyDomainMapper::toDto(const AuthorizationReply& reply)
{
    return {
        reply.isAuthorized(),
        reply.getMessageError()
    };
}

AuthorizationReply AuthorizationReplyDomainMapper::fromDto(const AuthorizationReplyDto& dto)
{
    return AuthorizationReply(dto.authorized, dto.messageError);
}
