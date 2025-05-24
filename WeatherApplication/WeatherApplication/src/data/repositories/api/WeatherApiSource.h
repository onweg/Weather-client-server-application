#ifndef WEATHERAPISOURCE_H
#define WEATHERAPISOURCE_H

#include <QFutureInterface>
#include <QNetworkAccessManager>
#include <QObject>
#include <functional>
#include <memory>

#include "../../../domain/interfaces/api/IApiWeatherSource.h"
#include "../../../domain/interfaces/config/IConfigProvider.h"
#include "../../../domain/interfaces/sharedstate/ISharedState.h"

class WeatherApiSource : public QObject, public IApiWeatherSource
{
	Q_OBJECT
  public:
	explicit WeatherApiSource(std::shared_ptr<IConfigProvider> config,
	                          QObject *parent = nullptr);
	QFuture<Result<WeekWeatherData>>
	findWeatherDataByCity(const std::string city) override;

  private:
	void initConfig();
	void handleCityCoordinatesReply(
	    QNetworkReply *reply,
	    QFutureInterface<Result<WeekWeatherData>> &futureInterface);
	void fetchWeatherByCoordinates(
	    const QString &lat, const QString &lon,
	    QFutureInterface<Result<WeekWeatherData>> &futureInterface);
	void handleWeatherReply(
	    QNetworkReply *reply,
	    QFutureInterface<Result<WeekWeatherData>> &futureInterface);
	void
	finishWithError(QFutureInterface<Result<WeekWeatherData>> &futureInterface,
	                const std::string &errorMessage, QNetworkReply *reply);
	QString buildCityRequestUrl(const std::string &city) const;
	Result<std::pair<QString, QString>>
	parseCityCoordinatesJson(QNetworkReply *reply);
	Result<WeekWeatherData> parseWeatherJson(QNetworkReply *reply);
	QFuture<Result<WeekWeatherData>> finishWithImmediateError(
	    QFutureInterface<Result<WeekWeatherData>> &futureInterface,
	    const std::string &errorMessage);

	std::shared_ptr<IConfigProvider> configProvider_;
	std::shared_ptr<ApiConfig> apiConfig_;
	QNetworkAccessManager *networkManager_;
};

#endif // WEATHERAPISOURCE_H
