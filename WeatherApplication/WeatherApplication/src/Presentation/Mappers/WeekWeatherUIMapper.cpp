#include "WeekWeatherUIMapper.h"

void WeekWeatherUiMapper::toUiModel(const WeekWeatherData& dto, WeekWeatherUiModel* uiModel) {
    if (!uiModel) return;

    uiModel->setCity(QString::fromStdString(dto.city));
    uiModel->setMessageError(QString::fromStdString(dto.messageError));
    uiModel->clearDailyWeather();

    for (const auto& weatherDto : dto.dailyWeather) {
        auto* weatherUi = new WeatherUiModel(uiModel);
        WeatherUiMapper::toUiModel(weatherDto, weatherUi);
        uiModel->addWeatherModel(weatherUi);
    }
}

WeekWeatherData WeekWeatherUiMapper::fromUiModel(const WeekWeatherUiModel* uiModel) {
    if (!uiModel)  return {};

    WeekWeatherData data;
    data.city = uiModel->city().toStdString();
    data.messageError = uiModel->messageError().toStdString();

    for (const auto* obj : uiModel->dailyWeather()) {
        const WeatherUiModel* weatherUi = qobject_cast<const WeatherUiModel*>(obj);
        if (weatherUi) {
            data.dailyWeather.push_back(WeatherUiMapper::fromUiModel(weatherUi));
        }
    }

    return data;
}
