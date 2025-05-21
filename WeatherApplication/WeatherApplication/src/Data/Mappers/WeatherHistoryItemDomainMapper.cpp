#include "WeatherHistoryItemDomainMapper.h"

WeatherHistoryItem WeatherHistoryItemDomainMapper::fromDto(const WeatherHistoryItemDto &dto)
{
    return WeatherHistoryItem(dto.id, dto.username, dto.timestamp, dto.city, dto.date);
}

WeatherHistoryItemDto WeatherHistoryItemDomainMapper::toDto(const WeatherHistoryItem &item)
{
    return {
        item.getId(),
        item.getUsername(),
        item.getTimestamp(),
        item.getCity(),
        item.getDate()
    };
}
