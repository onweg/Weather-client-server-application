#include "WeatherUIMapper.h"

void WeatherUiMapper::toUiModel(const WeatherData& dto, WeatherUiModel* uiModel) {
    if (!uiModel) return;

    uiModel->setCity(QString::fromStdString(dto.city));
    uiModel->setDate(QString::fromStdString(dto.date));
    uiModel->setDescription(QString::fromStdString(dto.description));
    uiModel->setLat(dto.lat);
    uiModel->setLon(dto.lon);
    uiModel->setTemp(dto.temp);
    uiModel->setFeelsLike(dto.feels_like);
    uiModel->setTempMax(dto.temp_max);
    uiModel->setTempMin(dto.temp_min);
    uiModel->setWindSpeed(dto.wind_speed);
    uiModel->setHumidity(dto.humidity);
    uiModel->setPressure(dto.pressure);
    uiModel->setMessageError(QString::fromStdString(dto.messageError));
}

WeatherData WeatherUiMapper::fromUiModel(const WeatherUiModel* uiModel) {
    if (!uiModel) return {};

    return WeatherData{
        uiModel->lat(),
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
        uiModel->messageError().toStdString()
    };
}
