#ifndef SQLITEWEATHERHISTORYREPOSITORY_H
#define SQLITEWEATHERHISTORYREPOSITORY_H

#include <QSqlQuery>
#include <memory>

#include "../../../Domain/Interfaces/Database/IWeatherDatabaseConnection.h"
#include "../../../Domain/Interfaces/Database/IWeatherDatabaseInitializer.h"
#include "../../../Domain/Interfaces/Database/IWeatherHistoryRepository.h"
#include "../../../Domain/Interfaces/SharedState/ISharedState.h"
#include "../../DtoModels/WeatherHistoryItemDto.h"

class SqliteWeatherHistoryRepository : public IWeatherHistoryRepository
{
  public:
	explicit SqliteWeatherHistoryRepository(
	    std::shared_ptr<IWeatherDatabaseInitializer> dbInitializer,
	    std::shared_ptr<ISharedState> state);

	void save(const std::string &city, const std::string &date) override;
	std::vector<WeatherHistoryItem> getAll() override;

  private:
	std::shared_ptr<ISharedState> sharedState_;
	std::shared_ptr<IWeatherDatabaseConnection> connection_;

	bool executeQuery(QSqlQuery &query, const char *errorMessage);
	void prepareInsertStatement(QSqlQuery &query);
	void bindInsertValues(QSqlQuery &query, const WeatherHistoryItemDto &dto);
	WeatherHistoryItem extractWeatherHistoryItem(const QSqlQuery &query);
	WeatherHistoryItemDto extractWeatherHistoryItemDto(const QSqlQuery &query);
};

#endif // SQLITEWEATHERHISTORYREPOSITORY_H
