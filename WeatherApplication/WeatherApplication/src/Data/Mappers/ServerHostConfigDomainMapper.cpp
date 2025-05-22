#include "ServerHostConfigDomainMapper.h"

ServerHostConfigDto
ServerHostConfigDomainMapper::toDto(const ServerHostConfig &config)
{
	return {config.getIp(), config.getPort()};
}

ServerHostConfig
ServerHostConfigDomainMapper::fromDto(const ServerHostConfigDto &dto)
{
	return ServerHostConfig(dto.ip, dto.port);
}
