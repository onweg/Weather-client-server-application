#include "SharedState.h"

SharedState::SharedState() {}

std::string SharedState::getUsername()
{
	return username_;
}

void SharedState::setUsername(const std::string &username)
{
	if (username_ != username)
	{
		username_ = username;
	}
}
