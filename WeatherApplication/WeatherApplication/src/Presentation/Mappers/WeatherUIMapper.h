#ifndef WEATHERUIMAPPER_H
#define WEATHERUIMAPPER_H

#include "../../Data/DtoModels/WeatherDataDto.h"
#include "../UIModels/WeatherUIModel.h"

class WeatherUiMapper {
public:
    static void toUiModel(const WeatherDataDto& dto, WeatherUiModel* uiModel);
    static WeatherDataDto fromUiModel(const WeatherUiModel* uiModel);
};

#endif // WEATHERUIMAPPER_H
