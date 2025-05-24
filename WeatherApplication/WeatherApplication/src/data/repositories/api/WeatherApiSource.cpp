#include "WeatherApiSource.h"

#include <QFutureInterface>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QNetworkReply>
#include <QNetworkRequest>

#include "../../../utils/WeatherJsonConverter.h"
#include "../../dtomodels/WeekWeatherDataDto.h"
#include "../../mappers/WeekWeatherDomainMapper.h"

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
    initConfig();
	auto url = apiConfig_->buildFindCityByNameUrl(QString::fromStdString(city));
	auto *reply = networkManager_->get(QNetworkRequest(url));
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

void WeatherApiSource::initConfig()
{
    if (!apiConfig_)
    {
        apiConfig_ = std::make_shared<ApiConfig>();
        *apiConfig_ = configProvider_->getApiConfig();
    }
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
	auto url = apiConfig_->buildWeatherByCoordinatesUrl(lat.toDouble(),
	                                                    lon.toDouble());
	QNetworkReply *reply = networkManager_->get(QNetworkRequest(url));

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
