#ifndef AUTHORIZATIONREQUESTDTO_H
#define AUTHORIZATIONREQUESTDTO_H

#include <string>

struct AuthorizationRequestDto
{
	std::string username;
	std::string passwordHash;
};

#endif // AUTHORIZATIONREQUESTDTO_H
