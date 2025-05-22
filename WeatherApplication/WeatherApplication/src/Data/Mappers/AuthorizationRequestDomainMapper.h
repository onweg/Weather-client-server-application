#ifndef AUTHORIZATIONREQUESTDOMAINMAPPER_H
#define AUTHORIZATIONREQUESTDOMAINMAPPER_H

#include "../../Domain/Entities/AuthorizationRequest.h"
#include "../DtoModels/AuthorizationRequestDto.h"

class AuthorizationRequestDomainMapper
{
  public:
	static AuthorizationRequestDto toDto(const AuthorizationRequest &request);
	static AuthorizationRequest fromDto(const AuthorizationRequestDto &dto);
};

#endif // AUTHORIZATIONREQUESTDOMAINMAPPER_H
