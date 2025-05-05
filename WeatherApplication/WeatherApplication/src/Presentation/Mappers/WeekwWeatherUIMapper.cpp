#include "WeekWeatherUIMapper.h"

void WeekWeatherUiMapper::toUiModel(const WeekWeatherDataDto& dto, WeekWeatherUiModel* uiModel) {
    if (!uiModel) return;

    uiModel->setCity(QString::fromStdString(dto.city));
    uiModel->setMessageError(QString::fromStdString(dto.messageError));
    uiModel->clearDailyWeather();

    for (const auto& weatherDto : dto.dailyWeather) {
        auto* weatherUi = new WeatherUiModel(uiModel); // parent = uiModel for auto cleanup
        WeatherUiMapper::toUiModel(weatherDto, weatherUi);
        uiModel->addWeatherModel(weatherUi);
    }
}

WeekWeatherDataDto WeekWeatherUiMapper::fromUiModel(const WeekWeatherUiModel* uiModel) {
    if (!uiModel) return {};

    WeekWeatherDataDto dto;
    dto.city = uiModel->city().toStdString();
    dto.messageError = uiModel->messageError().toStdString();

    for (const auto* obj : uiModel->dailyWeather()) {
        const WeatherUiModel* weatherUi = qobject_cast<const WeatherUiModel*>(obj);
        if (weatherUi) {
            dto.dailyWeather.push_back(WeatherUiMapper::fromUiModel(weatherUi));
        }
    }

    return dto;
}
