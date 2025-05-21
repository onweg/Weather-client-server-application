#include "WeatherDatabaseInitializer.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "QtDatabaseConnection.h"

class WeatherDatabaseInitializer::Impl {
public:
    QSqlDatabase db;
};

WeatherDatabaseInitializer::WeatherDatabaseInitializer()
    : pimpl_(std::make_unique<Impl>()) {}

WeatherDatabaseInitializer::~WeatherDatabaseInitializer() = default;

DatabaseConnectionPtr WeatherDatabaseInitializer::initialize() {
    if (!connectToDatabase()) {
        qWarning() << "Не удалось подключиться к БД";
        return nullptr;
    }

    if (!createTableIfNotExists()) {
        qWarning() << "Не удалось создать таблицу";
        return nullptr;
    }

    return std::make_shared<QtDatabaseConnection>(pimpl_->db);
}

bool WeatherDatabaseInitializer::connectToDatabase() {
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        pimpl_->db = QSqlDatabase::database();
        return true;
    }

    pimpl_->db = QSqlDatabase::addDatabase("QSQLITE");
    pimpl_->db.setDatabaseName(DB_PATH);

    if (!pimpl_->db.open()) {
        qDebug() << "Ошибка подключения к БД:" << pimpl_->db.lastError();
        return false;
    }

    return true;
}

bool WeatherDatabaseInitializer::createTableIfNotExists() {
    QSqlQuery query(pimpl_->db);
    bool ok = query.exec(
        "CREATE TABLE IF NOT EXISTS weather_data ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "username TEXT, "
        "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP, "
        "city TEXT, "
        "date TEXT)"
    );

    if (!ok) {
        qDebug() << "Ошибка при создании таблицы:" << query.lastError();
    }

    return ok;
}
