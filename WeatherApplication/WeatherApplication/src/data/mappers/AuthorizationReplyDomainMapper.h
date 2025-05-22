#ifndef AUTHORIZATIONREPLYDOMAINMAPPER_H
#define AUTHORIZATIONREPLYDOMAINMAPPER_H

#include "../../domain/entities/AuthorizationReply.h"
#include "../dtomodels/AuthorizationReplyDto.h"

class AuthorizationReplyDomainMapper
{
  public:
	static AuthorizationReplyDto toDto(const AuthorizationReply &reply);
	static AuthorizationReply fromDto(const AuthorizationReplyDto &dto);
};

#endif // AUTHORIZATIONREPLYDOMAINMAPPER_H
