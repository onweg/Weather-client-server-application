#include "WeatherDomainMapper.h"

WeatherDataDto WeatherDomainMapper::toDto(const WeatherData &domain)
{
	return WeatherDataDto{
	    domain.getLat(),         domain.getLon(),         domain.getCity(),
	    domain.getDate(),        domain.getDescription(), domain.getTemp(),
	    domain.getFeelsLike(),   domain.getTempMax(),     domain.getTempMin(),
	    domain.getWindSpeed(),   domain.getHumidity(),    domain.getPressure(),
	    domain.getMessageError()};
}

WeatherData WeatherDomainMapper::fromDto(const WeatherDataDto &dto)
{
	return WeatherData{dto.lat,         dto.lon,         dto.city,
	                   dto.date,        dto.description, dto.temp,
	                   dto.feelsLike,   dto.tempMax,     dto.tempMin,
	                   dto.windSpeed,   dto.humidity,    dto.pressure,
	                   dto.messageError};
}
