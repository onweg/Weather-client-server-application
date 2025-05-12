#ifndef SQLITEWEATHERHISTORYREPOSITORY_H
#define SQLITEWEATHERHISTORYREPOSITORY_H

#include "../../../Domain/Interfaces/Database/IWeatherDatabaseInitializer.h"
#include "../../../Domain/Interfaces/Database/IWeatherHistoryRepository.h"
#include "../../../Domain/Interfaces/SharedState/ISharedState.h"
#include <QSqlDatabase>
#include <memory>

class SqliteWeatherHistoryRepository : public IWeatherHistoryRepository {
public:
 SqliteWeatherHistoryRepository(
	 std::shared_ptr<IWeatherDatabaseInitializer> dbInitializer,
	 std::shared_ptr<ISharedState> state);
 std::vector<WeatherHistoryItem> getAll() override;
 void save(const std::string &city, const std::string &date) override;

private:
 QSqlDatabase db_;
 std::shared_ptr<ISharedState> sharedState_;
};

#endif	// SQLITEWEATHERHISTORYREPOSITORY_H
