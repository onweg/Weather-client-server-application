#ifndef WEEKWEATHERUIMAPPER_H
#define WEEKWEATHERUIMAPPER_H

#include "../../Data/DtoModels/WeekWeatherDataDto.h"
#include "../UIModels/WeekWeatherUIModel.h"
#include "WeatherUIMapper.h"

class WeekWeatherUiMapper {
public:
    static void toUiModel(const WeekWeatherDataDto& dto, WeekWeatherUiModel* uiModel);
    static WeekWeatherDataDto fromUiModel(const WeekWeatherUiModel* uiModel);
};

#endif // WEEKWEATHERUIMAPPER_H
