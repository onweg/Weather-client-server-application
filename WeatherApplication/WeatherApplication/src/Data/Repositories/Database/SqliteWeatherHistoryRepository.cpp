#include "SqliteWeatherHistoryRepository.h"
#include "QtDatabaseConnection.h"
#include "../../Mappers/WeatherHistoryItemDomainMapper.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDateTime>
#include <QDebug>

SqliteWeatherHistoryRepository::SqliteWeatherHistoryRepository(
    std::shared_ptr<IWeatherDatabaseInitializer> dbInitializer,
    std::shared_ptr<ISharedState> state)
    : sharedState_(std::move(state))
{
    auto connection = dbInitializer->initialize();
    if (!connection || !connection->isOpen()) {
        qWarning() << "Нет подключения к БД";
    } else {
        connection_ = connection;
    }
}

void SqliteWeatherHistoryRepository::save(const std::string &city, const std::string &date) {
    auto qtConn = dynamic_cast<QtDatabaseConnection*>(connection_.get());
    if (!qtConn) {
        qWarning() << "Неверный тип соединения";
        return;
    }

    QSqlDatabase db = qtConn->getQtDatabase();
    QSqlQuery query(db);

    prepareInsertStatement(query);

    WeatherHistoryItemDto dto;
    dto.username = sharedState_->getUsername();
    dto.city = city;
    dto.date = date;

    bindInsertValues(query, dto);

    if (!executeQuery(query, "Ошибка при вставке")) return;
}

std::vector<WeatherHistoryItem> SqliteWeatherHistoryRepository::getAll() {
    std::vector<WeatherHistoryItem> results;

    auto qtConn = dynamic_cast<QtDatabaseConnection*>(connection_.get());
    if (!qtConn) {
        qWarning() << "Неверный тип соединения";
        return results;
    }

    QSqlDatabase db = qtConn->getQtDatabase();
    QSqlQuery query("SELECT id, username, timestamp, city, date FROM weather_data", db);

    if (!executeQuery(query, "Ошибка при получении данных")) return results;

    while (query.next()) {
        WeatherHistoryItemDto dto = extractWeatherHistoryItemDto(query);
        results.push_back(WeatherHistoryItemDomainMapper::fromDto(dto));
    }

    return results;
}

bool SqliteWeatherHistoryRepository::executeQuery(QSqlQuery &query, const char *errorMessage) {
    if (!query.exec()) {
        qDebug() << errorMessage << ":" << query.lastError();
        return false;
    }
    return true;
}

void SqliteWeatherHistoryRepository::prepareInsertStatement(QSqlQuery &query) {
    bool ok = query.prepare("INSERT INTO weather_data (username, city, date) VALUES (:username, :city, :date)");
    Q_ASSERT(ok);
}

void SqliteWeatherHistoryRepository::bindInsertValues(QSqlQuery &query, const WeatherHistoryItemDto& dto) {
    query.bindValue(":username", QString::fromStdString(dto.username));
    query.bindValue(":city", QString::fromStdString(dto.city));
    query.bindValue(":date", QString::fromStdString(dto.date));
}

WeatherHistoryItemDto SqliteWeatherHistoryRepository::extractWeatherHistoryItemDto(const QSqlQuery &query) {
    WeatherHistoryItemDto dto;
    dto.id = query.value("id").toInt();
    dto.username = query.value("username").toString().toStdString();
    dto.city = query.value("city").toString().toStdString();
    dto.date = query.value("date").toString().toStdString();
    dto.timestamp = std::chrono::system_clock::from_time_t(
        static_cast<std::time_t>(query.value("timestamp").toDateTime().toMSecsSinceEpoch() / 1000));
    return dto;
}
