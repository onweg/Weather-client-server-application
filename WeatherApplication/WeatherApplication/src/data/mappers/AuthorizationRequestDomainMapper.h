#ifndef AUTHORIZATIONREQUESTDOMAINMAPPER_H
#define AUTHORIZATIONREQUESTDOMAINMAPPER_H

#include "../../domain/entities/AuthorizationRequest.h"
#include "../dtomodels/AuthorizationRequestDto.h"

class AuthorizationRequestDomainMapper
{
  public:
	static AuthorizationRequestDto toDto(const AuthorizationRequest &request);
	static AuthorizationRequest fromDto(const AuthorizationRequestDto &dto);
};

#endif // AUTHORIZATIONREQUESTDOMAINMAPPER_H
