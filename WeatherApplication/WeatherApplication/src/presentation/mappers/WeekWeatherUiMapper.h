#ifndef WEEKWEATHERUIMAPPER_H
#define WEEKWEATHERUIMAPPER_H

#include "../../domain/entities/WeekWeatherData.h"
#include "../uimodels/WeekWeatherUiModel.h"

class WeekWeatherUiMapper
{
  public:
	static void toUiModel(const WeekWeatherData &dto,
	                      WeekWeatherUiModel *uiModel);
	static WeekWeatherData fromUiModel(const WeekWeatherUiModel *uiModel);
};

#endif // WEEKWEATHERUIMAPPER_H
