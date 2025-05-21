#ifndef AUTHORIZATIONREPLYDOMAINMAPPER_H
#define AUTHORIZATIONREPLYDOMAINMAPPER_H

#include "../DtoModels/AuthorizationReplyDto.h"
#include "../../Domain/Entities/AuthorizationReply.h"

class AuthorizationReplyDomainMapper
{
public:
    static AuthorizationReplyDto toDto(const AuthorizationReply& reply);
    static AuthorizationReply fromDto(const AuthorizationReplyDto& dto);
};

#endif // AUTHORIZATIONREPLYDOMAINMAPPER_H
