#include "SqliteWeatherHistoryRepository.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QVariant>
#include <QDateTime>
#include "../../mappers/WeatherHistoryItemDomainMapper.h"


SqliteWeatherHistoryRepository::SqliteWeatherHistoryRepository(std::shared_ptr<IWeatherDatabaseInitializer> dbInit, std::shared_ptr<ISharedState> state)
    :dbInitializer_(std::move(dbInit)), sharedState_(std::move(state))
{
    db_ = dbInitializer_->initialize();
    if (!db_.isOpen())
    {
     qWarning() << "База данных не открыта!";
    } else {
        qDebug() << "База данных открыта!";
    }
}

void SqliteWeatherHistoryRepository::save(const std::string &city, const std::string &date)
{
 QSqlQuery query(db_);
 query.prepare("INSERT INTO weather_data (username, city, date) VALUES (:username, :city, :date)");
 bindInsertValues(query, city, date);

 if (!executeQuery(query, "Ошибка при вставке"))
  return;
}

std::vector<WeatherHistoryItem> SqliteWeatherHistoryRepository::getAll()
{
    QSqlQuery query = fetchData();
    if (!query.isActive()) {
        return {};
    }
    std::vector<WeatherHistoryItemDto> dtos = mapToDtos(query);
    std::vector<WeatherHistoryItem> items;
    for (const auto& dto : dtos) {
        items.push_back(WeatherHistoryItemDomainMapper::fromDto(dto));
    }
    return items;
}

bool SqliteWeatherHistoryRepository::executeQuery(QSqlQuery &query, const char *errorMessage)
{
 if (!query.exec())
 {
  qDebug() << errorMessage << ":" << query.lastError();
  return false;
 }
 return true;
}

void SqliteWeatherHistoryRepository::bindInsertValues(QSqlQuery &query, const std::string &city, const std::string &date)
{
 query.bindValue(":username", QString::fromStdString(sharedState_->getUsername()));
 query.bindValue(":city", QString::fromStdString(city));
 query.bindValue(":date", QString::fromStdString(date));
}

QSqlQuery SqliteWeatherHistoryRepository::fetchData()
{
    QSqlQuery query("SELECT id, username, timestamp, city, date FROM weather_data", db_);
    if (!executeQuery(query, "Ошибка при получении данных")) {
        return QSqlQuery(); // пустой запрос
    }
    return query;
}

std::vector<WeatherHistoryItemDto> SqliteWeatherHistoryRepository::mapToDtos(QSqlQuery &query)
{
    std::vector<WeatherHistoryItemDto> dtos;
    while (query.next()) {
        dtos.push_back(mapRowToDto(query));
    }
    return dtos;
}

WeatherHistoryItemDto SqliteWeatherHistoryRepository::mapRowToDto(QSqlQuery &query)
{
    WeatherHistoryItemDto dto;
    dto.id = query.value("id").toInt();
    dto.username = query.value("username").toString().toStdString();
    dto.city = query.value("city").toString().toStdString();
    dto.date = query.value("date").toString().toStdString();
    QDateTime dt = query.value("timestamp").toDateTime();
    qint64 msecs = dt.toMSecsSinceEpoch();
    dto.timestamp = std::chrono::system_clock::from_time_t(msecs / 1000); // в секундах
    return dto;
}
