#include "WeatherUiModel.h"

WeatherUiModel::WeatherUiModel(QObject *parent) : QObject(parent) {}

QString WeatherUiModel::city() const
{
	return city_;
}

QString WeatherUiModel::date() const
{
	return date_;
}

QString WeatherUiModel::description() const
{
	return description_;
}

double WeatherUiModel::lat() const
{
	return lat_;
}

double WeatherUiModel::lon() const
{
	return lon_;
}

double WeatherUiModel::temp() const
{
	return temp_;
}

double WeatherUiModel::feelsLike() const
{
	return feelsLike_;
}

double WeatherUiModel::tempMax() const
{
	return tempMax_;
}

double WeatherUiModel::tempMin() const
{
	return tempMin_;
}

double WeatherUiModel::windSpeed() const
{
	return windSpeed_;
}

int WeatherUiModel::humidity() const
{
	return humidity_;
}

int WeatherUiModel::pressure() const
{
	return pressure_;
}

QString WeatherUiModel::messageError() const
{
	return messageError_;
}

void WeatherUiModel::setCity(const QString &val)
{
	if (city_ != val)
	{
		city_ = val;
		emit cityChanged();
	}
}

void WeatherUiModel::setDate(const QString &val)
{
	if (date_ != val)
	{
		date_ = val;
		emit dateChanged();
	}
}

void WeatherUiModel::setDescription(const QString &val)
{
	if (description_ != val)
	{
		description_ = val;
		emit descriptionChanged();
	}
}

void WeatherUiModel::setLat(double val)
{
	if (!qFuzzyCompare(lat_, val))
	{
		lat_ = val;
		emit latChanged();
	}
}

void WeatherUiModel::setLon(double val)
{
	if (!qFuzzyCompare(lon_, val))
	{
		lon_ = val;
		emit lonChanged();
	}
}

void WeatherUiModel::setTemp(double val)
{
	if (!qFuzzyCompare(temp_, val))
	{
		temp_ = val;
		emit tempChanged();
	}
}

void WeatherUiModel::setFeelsLike(double val)
{
	if (!qFuzzyCompare(feelsLike_, val))
	{
		feelsLike_ = val;
		emit feelsLikeChanged();
	}
}

void WeatherUiModel::setTempMax(double val)
{
	if (!qFuzzyCompare(tempMax_, val))
	{
		tempMax_ = val;
		emit tempMaxChanged();
	}
}

void WeatherUiModel::setTempMin(double val)
{
	if (!qFuzzyCompare(tempMin_, val))
	{
		tempMin_ = val;
		emit tempMinChanged();
	}
}

void WeatherUiModel::setWindSpeed(double val)
{
	if (!qFuzzyCompare(windSpeed_, val))
	{
		windSpeed_ = val;
		emit windSpeedChanged();
	}
}

void WeatherUiModel::setHumidity(int val)
{
	if (humidity_ != val)
	{
		humidity_ = val;
		emit humidityChanged();
	}
}

void WeatherUiModel::setPressure(int val)
{
	if (pressure_ != val)
	{
		pressure_ = val;
		emit pressureChanged();
	}
}

void WeatherUiModel::setMessageError(const QString &val)
{
	if (messageError_ != val)
	{
		messageError_ = val;
		emit messageErrorChanged();
	}
}
