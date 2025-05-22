#include "WeatherUiMapper.h"

void WeatherUiMapper::toUiModel(const WeatherData &domain,
                                WeatherUiModel *uiModel)
{
	if (!uiModel)
		return;

	uiModel->setCity(QString::fromStdString(domain.getCity()));
	uiModel->setDate(QString::fromStdString(domain.getDate()));
	uiModel->setDescription(QString::fromStdString(domain.getDescription()));
	uiModel->setLat(domain.getLat());
	uiModel->setLon(domain.getLon());
	uiModel->setTemp(domain.getTemp());
	uiModel->setFeelsLike(domain.getFeelsLike());
	uiModel->setTempMax(domain.getTempMax());
	uiModel->setTempMin(domain.getTempMin());
	uiModel->setWindSpeed(domain.getWindSpeed());
	uiModel->setHumidity(domain.getHumidity());
	uiModel->setPressure(domain.getPressure());
	uiModel->setMessageError(QString::fromStdString(domain.getMessageError()));
}

WeatherData WeatherUiMapper::fromUiModel(const WeatherUiModel *uiModel)
{
	if (!uiModel)
		return {};

	return WeatherData{uiModel->lat(),
	                   uiModel->lon(),
	                   uiModel->city().toStdString(),
	                   uiModel->date().toStdString(),
	                   uiModel->description().toStdString(),
	                   uiModel->temp(),
	                   uiModel->feelsLike(),
	                   uiModel->tempMax(),
	                   uiModel->tempMin(),
	                   uiModel->windSpeed(),
	                   uiModel->humidity(),
	                   uiModel->pressure(),
	                   uiModel->messageError().toStdString()};
}
