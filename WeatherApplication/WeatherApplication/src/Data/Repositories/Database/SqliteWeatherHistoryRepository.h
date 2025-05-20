#ifndef SQLITEWEATHERHISTORYREPOSITORY_H
#define SQLITEWEATHERHISTORYREPOSITORY_H

#include <QSqlDatabase>
#include <QDateTime>
#include <memory>
#include "../../../Domain/Interfaces/Database/IWeatherHistoryRepository.h"
#include "../../../Domain/Interfaces/Database/IWeatherDatabaseInitializer.h"
#include "../../../Domain/Interfaces/SharedState/ISharedState.h"

class SqliteWeatherHistoryRepository : public IWeatherHistoryRepository {
public:
    SqliteWeatherHistoryRepository(std::shared_ptr<IWeatherDatabaseInitializer> dbInitializer, std::shared_ptr<ISharedState> state);
    std::vector<WeatherHistoryItem> getAll() override;
    void save(const std::string &city, const std::string &date) override;

private:
    QSqlDatabase db_;
    std::shared_ptr<ISharedState> sharedState_;

    WeatherHistoryItem extractWeatherHistoryItem(const QSqlQuery& query);
    std::chrono::system_clock::time_point convertToTimePoint(const QDateTime& dateTime);
    bool executeQuery(QSqlQuery& query, const char* errorMessage);
    void prepareInsertStatement(QSqlQuery& query);
    void bindInsertValues(QSqlQuery& query, const std::string& city, const std::string& date);
};

#endif // SQLITEWEATHERHISTORYREPOSITORY_H
