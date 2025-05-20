#include "SqliteWeatherHistoryRepository.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDateTime>
#include <QDebug>

SqliteWeatherHistoryRepository::SqliteWeatherHistoryRepository(std::shared_ptr<IWeatherDatabaseInitializer> dbInitializer, std::shared_ptr<ISharedState> state)
    :sharedState_(std::move(state))
{
    dbInitializer->initialize();
    db_ = QSqlDatabase::database();
    if (!db_.isOpen()) {
        qWarning() << "База данных не открыта!";
    }
}

std::vector<WeatherHistoryItem> SqliteWeatherHistoryRepository::getAll() {
    std::vector<WeatherHistoryItem> results;
    QSqlQuery query("SELECT id, username, timestamp, city, date FROM weather_data");
    if (!executeQuery(query, "Ошибка при получении данных")) return results;
    while (query.next()) {
        results.push_back(extractWeatherHistoryItem(query));
    }
    return results;
}

void SqliteWeatherHistoryRepository::save(const std::string &city, const std::string &date) {
    QSqlQuery query;
    prepareInsertStatement(query);
    bindInsertValues(query, city, date);
    if (!executeQuery(query, "Ошибка при вставке")) return;
}

WeatherHistoryItem SqliteWeatherHistoryRepository::extractWeatherHistoryItem(const QSqlQuery &query) {
    WeatherHistoryItem item;
    item.id = query.value("id").toInt();
    item.username = query.value("username").toString().toStdString();
    item.city = query.value("city").toString().toStdString();
    item.date = query.value("date").toString().toStdString();
    item.timestamp = convertToTimePoint(query.value("timestamp").toDateTime());
    return item;
}

std::chrono::system_clock::time_point SqliteWeatherHistoryRepository::convertToTimePoint(const QDateTime &dateTime) {
    return std::chrono::system_clock::from_time_t(static_cast<std::time_t>(dateTime.toMSecsSinceEpoch() / 1000));
}

bool SqliteWeatherHistoryRepository::executeQuery(QSqlQuery &query, const char *errorMessage) {
    if (!query.exec()) {
        qDebug() << errorMessage << ":" << query.lastError();
        return false;
    }
    return true;
}

void SqliteWeatherHistoryRepository::prepareInsertStatement(QSqlQuery &query) {
    bool ok = query.prepare("INSERT INTO weather_data (username, city, date) "
                                "VALUES (:username, :city, :date)");
    Q_ASSERT(ok);
}

void SqliteWeatherHistoryRepository::bindInsertValues(QSqlQuery &query, const std::string &city, const std::string &date) {
    query.bindValue(":username", QString::fromStdString(sharedState_->getUsername()));
    query.bindValue(":city", QString::fromStdString(city));
    query.bindValue(":date", QString::fromStdString(date));
}
