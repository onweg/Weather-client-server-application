#ifndef WEATHERHISTORYITEMDOMAINMAPPER_H
#define WEATHERHISTORYITEMDOMAINMAPPER_H

#include "../../domain/entities/WeatherHistoryItem.h"
#include "../dtomodels/WeatherHistoryItemDto.h"

class WeatherHistoryItemDomainMapper
{
  public:
	static WeatherHistoryItem fromDto(const WeatherHistoryItemDto &dto);
	static WeatherHistoryItemDto toDto(const WeatherHistoryItem &item);
	;
};

#endif // WEATHERHISTORYITEMDOMAINMAPPER_H
