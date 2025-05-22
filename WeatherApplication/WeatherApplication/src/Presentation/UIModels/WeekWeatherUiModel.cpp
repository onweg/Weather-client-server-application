#include "WeekWeatherUiModel.h"

WeekWeatherUiModel::WeekWeatherUiModel(QObject *parent) : QObject(parent) {}

QString WeekWeatherUiModel::city() const
{
	return city_;
}

QString WeekWeatherUiModel::messageError() const
{
	return messageError_;
}

QList<QObject *> WeekWeatherUiModel::dailyWeather() const
{
	return dailyWeather_;
}

void WeekWeatherUiModel::setCity(const QString &val)
{
	if (city_ != val)
	{
		city_ = val;
		emit cityChanged();
	}
}

void WeekWeatherUiModel::setMessageError(const QString &val)
{
	if (messageError_ != val)
	{
		messageError_ = val;
		emit messageErrorChanged();
	}
}

void WeekWeatherUiModel::setDailyWeather(const QList<QObject *> &list)
{
	dailyWeather_ = list;
	emit dailyWeatherChanged();
}

void WeekWeatherUiModel::clearDailyWeather()
{
	qDeleteAll(dailyWeather_);
	dailyWeather_.clear();
	emit dailyWeatherChanged();
}

void WeekWeatherUiModel::addWeatherModel(QObject *model)
{
	dailyWeather_.append(model);
	emit dailyWeatherChanged();
}
