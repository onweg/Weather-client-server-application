#include "ApiConfigDomainMapper.h"

ApiConfig ApiConfigDomainMapper::fromDto(const ApiConfigDto &dto)
{
    return ApiConfig(QString::fromStdString(dto.baseUrl_), QString::fromStdString(dto.key));
}
