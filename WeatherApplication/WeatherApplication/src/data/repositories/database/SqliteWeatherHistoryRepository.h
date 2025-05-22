#ifndef SQLITEWEATHERHISTORYREPOSITORY_H
#define SQLITEWEATHERHISTORYREPOSITORY_H

#include <QSqlQuery>
#include <memory>

#include "../../../domain/interfaces/database/IWeatherDatabaseConnection.h"
#include "../../../domain/interfaces/database/IWeatherDatabaseInitializer.h"
#include "../../../domain/interfaces/database/IWeatherHistoryRepository.h"
#include "../../../domain/interfaces/sharedstate/ISharedState.h"
#include "../../dtomodels/WeatherHistoryItemDto.h"

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
