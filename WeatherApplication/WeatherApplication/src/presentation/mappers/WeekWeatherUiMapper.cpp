#include "WeekWeatherUiMapper.h"

#include "WeatherUiMapper.h"

void WeekWeatherUiMapper::toUiModel(const WeekWeatherData &domain,
                                    WeekWeatherUiModel *uiModel)
{
	if (!uiModel)
		return;
	uiModel->setCity(QString::fromStdString(domain.getCity()));
	uiModel->setMessageError(QString::fromStdString(domain.getMessageError()));
	uiModel->clearDailyWeather();
	for (const auto &weatherDto : domain.getDailyWeather())
	{
		auto *weatherUi = new WeatherUiModel(uiModel);
		WeatherUiMapper::toUiModel(weatherDto, weatherUi);
		uiModel->addWeatherModel(weatherUi);
	}
}

WeekWeatherData
WeekWeatherUiMapper::fromUiModel(const WeekWeatherUiModel *uiModel)
{
	if (!uiModel)
		return {};
	WeekWeatherData data;
	data.setCity(uiModel->city().toStdString());
	data.setMessageError(uiModel->messageError().toStdString());
	const QList<QObject *> &weatherList = uiModel->dailyWeather();
	std::vector<WeatherData> daily;
	for (const auto *obj : weatherList)
	{
		const WeatherUiModel *weatherUi =
		    qobject_cast<const WeatherUiModel *>(obj);
		if (weatherUi)
		{
			daily.push_back(WeatherUiMapper::fromUiModel(weatherUi));
		}
	}
	data.setDailyWeather(daily);

	return data;
}
