#include "WeatherUIModel.h"

WeatherUiModel::WeatherUiModel(QObject *parent) : QObject(parent) {}

QString WeatherUiModel::city() const { return m_city; }

QString WeatherUiModel::date() const { return m_date; }

QString WeatherUiModel::description() const { return m_description; }

double WeatherUiModel::lat() const { return m_lat; }

double WeatherUiModel::lon() const { return m_lon; }

double WeatherUiModel::temp() const { return m_temp; }

double WeatherUiModel::feelsLike() const { return m_feelsLike; }

double WeatherUiModel::tempMax() const { return m_tempMax; }

double WeatherUiModel::tempMin() const { return m_tempMin; }

double WeatherUiModel::windSpeed() const { return m_windSpeed; }

int WeatherUiModel::humidity() const { return m_humidity; }

int WeatherUiModel::pressure() const { return m_pressure; }

QString WeatherUiModel::messageError() const { return m_messageError; }

void WeatherUiModel::setCity(const QString &val) { if (m_city != val) { m_city = val; emit cityChanged(); }}

void WeatherUiModel::setDate(const QString &val) { if (m_date != val) { m_date = val; emit dateChanged(); }}

void WeatherUiModel::setDescription(const QString &val) { if (m_description != val) { m_description = val; emit descriptionChanged(); }}

void WeatherUiModel::setLat(double val) { if (!qFuzzyCompare(m_lat, val)) { m_lat = val; emit latChanged(); }}

void WeatherUiModel::setLon(double val) { if (!qFuzzyCompare(m_lon, val)) { m_lon = val; emit lonChanged(); }}

void WeatherUiModel::setTemp(double val) { if (!qFuzzyCompare(m_temp, val)) { m_temp = val; emit tempChanged(); }}

void WeatherUiModel::setFeelsLike(double val) { if (!qFuzzyCompare(m_feelsLike, val)) { m_feelsLike = val; emit feelsLikeChanged(); }}

void WeatherUiModel::setTempMax(double val) { if (!qFuzzyCompare(m_tempMax, val)) { m_tempMax = val; emit tempMaxChanged(); }}

void WeatherUiModel::setTempMin(double val) { if (!qFuzzyCompare(m_tempMin, val)) { m_tempMin = val; emit tempMinChanged(); }}

void WeatherUiModel::setWindSpeed(double val) { if (!qFuzzyCompare(m_windSpeed, val)) { m_windSpeed = val; emit windSpeedChanged(); }}

void WeatherUiModel::setHumidity(int val) { if (m_humidity != val) { m_humidity = val; emit humidityChanged(); }}

void WeatherUiModel::setPressure(int val) { if (m_pressure != val) { m_pressure = val; emit pressureChanged(); }}

void WeatherUiModel::setMessageError(const QString &val) { if (m_messageError != val) { m_messageError = val; emit messageErrorChanged(); }}

