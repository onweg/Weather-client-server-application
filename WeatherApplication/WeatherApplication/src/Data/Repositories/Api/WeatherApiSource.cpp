#include "WeatherApiSource.h"

#include <QFutureInterface>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QNetworkReply>
#include <QNetworkRequest>

#include "../../../Utils/WeatherJsonConverter.h"
#include "../../DtoModels/WeekWeatherDataDto.h"
#include "../../Mappers/WeekWeatherDomainMapper.h"

WeatherApiSource::WeatherApiSource(std::shared_ptr<IConfigProvider> config,
                                   QObject *parent)
 : QObject(parent), configProvider_(std::move(config))
{
	networkManager_ = new QNetworkAccessManager(this);
}

QFuture<Result<WeekWeatherData>>
WeatherApiSource::findWeatherDataByCity(const std::string city)
{
	QFutureInterface<Result<WeekWeatherData>> futureInterface;
	futureInterface.reportStarted();
	auto configResult = tryInitConfig();
	if (!configResult.isSuccess())
	{
		return finishWithImmediateError(futureInterface,
		                                configResult.errorMessage());
	}
	auto url = buildCityRequestUrl(city);
	auto *reply = networkManager_->get(QNetworkRequest(QUrl(url)));
	connect(reply, &QNetworkReply::finished, this,
	        [this, reply, futureInterface]() mutable
	        { handleCityCoordinatesReply(reply, futureInterface); });
	return futureInterface.future();
}

void WeatherApiSource::finishWithError(
    QFutureInterface<Result<WeekWeatherData>> &futureInterface,
    const std::string &errorMessage, QNetworkReply *reply)
{
	futureInterface.reportResult(
	    Result<WeekWeatherData>::failure(errorMessage));
	futureInterface.reportFinished();
	if (reply)
		reply->deleteLater();
}

QString WeatherApiSource::buildCityRequestUrl(const std::string &city) const
{
	QString cityName = QString::fromStdString(city);
	return QString::fromStdString(apiConfig_->getUrlFindCityByName())
	    .arg(cityName, QString::fromStdString(apiConfig_->getKey()));
}

Result<std::pair<QString, QString>>
WeatherApiSource::parseCityCoordinatesJson(QNetworkReply *reply)
{
	if (reply->error() != QNetworkReply::NoError)
	{
		return Result<std::pair<QString, QString>>::failure(
		    reply->errorString().toStdString());
	}
	QJsonParseError error;
	QJsonDocument doc = QJsonDocument::fromJson(reply->readAll(), &error);
	if (error.error != QJsonParseError::NoError || !doc.isArray() ||
	    doc.array().isEmpty())
	{
		return Result<std::pair<QString, QString>>::failure(
		    "Ошибка при получении координат города");
	}
	QJsonObject obj = doc.array().first().toObject();
	QString lat = QString::number(obj["lat"].toDouble());
	QString lon = QString::number(obj["lon"].toDouble());

	return Result<std::pair<QString, QString>>::success({lat, lon});
}

Result<WeekWeatherData> WeatherApiSource::parseWeatherJson(QNetworkReply *reply)
{
	if (reply->error() != QNetworkReply::NoError)
	{
		return Result<WeekWeatherData>::failure(
		    reply->errorString().toStdString());
	}
	QJsonParseError error;
	QJsonDocument doc = QJsonDocument::fromJson(reply->readAll(), &error);
	if (error.error != QJsonParseError::NoError || !doc.isObject())
	{
		return Result<WeekWeatherData>::failure(
		    "Ошибка парсинга JSON с погодой");
	}
	WeekWeatherDataDto dto =
	    WeatherJsonConverter::parseWeekWeather(doc.object());
	WeekWeatherData data = WeekWeatherDomainMapper::fromDto(dto);
	if (!data.getMessageError().empty())
	{
		return Result<WeekWeatherData>::failure(data.getMessageError());
	}
	return Result<WeekWeatherData>::success(data);
}

QFuture<Result<WeekWeatherData>> WeatherApiSource::finishWithImmediateError(
    QFutureInterface<Result<WeekWeatherData>> &futureInterface,
    const std::string &errorMessage)
{

	futureInterface.reportResult(
	    Result<WeekWeatherData>::failure(errorMessage));
	futureInterface.reportFinished();
	return futureInterface.future();
}

Result<void> WeatherApiSource::tryInitConfig()
{
	if (apiConfig_)
		return Result<void>::success();
	auto result = configProvider_->getApiConfig();
	if (!result.isSuccess())
	{
		throw std::runtime_error("Failed to load API configuration: " +
		                         result.errorMessage());
		// return Result<void>::failure(result.errorMessage());
	}
	apiConfig_ = std::make_shared<ApiConfig>(result.value());
	return Result<void>::success();
}

void WeatherApiSource::handleCityCoordinatesReply(
    QNetworkReply *reply,
    QFutureInterface<Result<WeekWeatherData>> &futureInterface)
{
	auto jsonResult = parseCityCoordinatesJson(reply);
	if (!jsonResult.isSuccess())
	{
		return finishWithError(futureInterface, jsonResult.errorMessage(),
		                       reply);
	}
	const auto &value = jsonResult.value();
	QString lat = value.first;
	QString lon = value.second;
	fetchWeatherByCoordinates(lat, lon, futureInterface);
	reply->deleteLater();
}

void WeatherApiSource::fetchWeatherByCoordinates(
    const QString &lat, const QString &lon,
    QFutureInterface<Result<WeekWeatherData>> &futureInterface)
{
	QString url =
	    QString::fromStdString(apiConfig_->getUrlFindWeatherByCoordinates())
	        .arg(lat, lon, QString::fromStdString(apiConfig_->getKey()));
	QNetworkReply *reply = networkManager_->get(QNetworkRequest(QUrl(url)));

	connect(reply, &QNetworkReply::finished, this,
	        [this, reply, futureInterface]() mutable
	        { handleWeatherReply(reply, futureInterface); });
}

void WeatherApiSource::handleWeatherReply(
    QNetworkReply *reply,
    QFutureInterface<Result<WeekWeatherData>> &futureInterface)
{
	auto weatherResult = parseWeatherJson(reply);
	if (!weatherResult.isSuccess())
	{
		return finishWithError(futureInterface, weatherResult.errorMessage(),
		                       reply);
	}
	futureInterface.reportResult(
	    Result<WeekWeatherData>::success(weatherResult.value()));
	futureInterface.reportFinished();
	reply->deleteLater();
}
