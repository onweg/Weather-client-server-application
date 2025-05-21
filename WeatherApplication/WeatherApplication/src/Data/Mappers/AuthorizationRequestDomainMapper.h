#ifndef AUTHORIZATIONREQUESTDOMAINMAPPER_H
#define AUTHORIZATIONREQUESTDOMAINMAPPER_H

#include "../DtoModels/AuthorizationRequestDto.h"
#include "../../Domain/Entities/AuthorizationRequest.h"

class AuthorizationRequestDomainMapper
{
public:
    static AuthorizationRequestDto toDto(const AuthorizationRequest& request);
    static AuthorizationRequest fromDto(const AuthorizationRequestDto& dto);
};

#endif // AUTHORIZATIONREQUESTDOMAINMAPPER_H
