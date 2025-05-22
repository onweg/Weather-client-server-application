#ifndef WEATHERUIMAPPER_H
#define WEATHERUIMAPPER_H

#include "../../domain/entities/WeatherData.h"
#include "../uimodels/WeatherUiModel.h"

class WeatherUiMapper
{
  public:
	static void toUiModel(const WeatherData &dto, WeatherUiModel *uiModel);
	static WeatherData fromUiModel(const WeatherUiModel *uiModel);
};

#endif // WEATHERUIMAPPER_H
