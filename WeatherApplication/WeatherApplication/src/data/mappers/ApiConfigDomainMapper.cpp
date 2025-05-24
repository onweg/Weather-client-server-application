#include "ApiConfigDomainMapper.h"

ApiConfig ApiConfigDomainMapper::fromDto(const ApiConfigDto &dto)
{
    return ApiConfig(QString::fromStdString(dto.baseUrl),
	                 QString::fromStdString(dto.key));
}
