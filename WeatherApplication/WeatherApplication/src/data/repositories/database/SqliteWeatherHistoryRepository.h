#ifndef SQLITEWEATHERHISTORYREPOSITORY_H
#define SQLITEWEATHERHISTORYREPOSITORY_H

#include <QSqlDatabase>
#include "../../../domain/interfaces/database/IWeatherHistoryRepository.h"
#include "../../../domain/interfaces/database/IWeatherDatabaseInitializer.h"
#include "../../../domain/interfaces/sharedstate/ISharedState.h"

#include "../../dtomodels/WeatherHistoryItemDto.h"

class SqliteWeatherHistoryRepository : public IWeatherHistoryRepository
{
  public:
 SqliteWeatherHistoryRepository(std::shared_ptr<IWeatherDatabaseInitializer> dbInit, std::shared_ptr<ISharedState> state);

 void save(const std::string &city, const std::string &date) override;
 std::vector<WeatherHistoryItem> getAll() override;

  private:
 QSqlDatabase db_;
  std::shared_ptr<IWeatherDatabaseInitializer> dbInitializer_;
 std::shared_ptr<ISharedState> sharedState_;


 bool executeQuery(QSqlQuery &query, const char *errorMessage);
 void bindInsertValues(QSqlQuery &query, const std::string &city, const std::string &date);
 QSqlQuery fetchData();
 std::vector<WeatherHistoryItemDto> mapToDtos(QSqlQuery &query);
 WeatherHistoryItemDto mapRowToDto(QSqlQuery &query);
};

#endif // SQLITEWEATHERHISTORYREPOSITORY_H
