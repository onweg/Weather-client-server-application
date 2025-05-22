#include "AuthorizationRequestDomainMapper.h"

AuthorizationRequestDto
AuthorizationRequestDomainMapper::toDto(const AuthorizationRequest &request)
{
	AuthorizationRequestDto dto;
	dto.username = request.getUsername();
	dto.passwordHash = request.getPasswordHash();
	return dto;
}

AuthorizationRequest
AuthorizationRequestDomainMapper::fromDto(const AuthorizationRequestDto &dto)
{
	return AuthorizationRequest(dto.username, dto.passwordHash);
}
