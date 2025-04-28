#include "DatabaseCreator.h"

DatabaseCreator::DatabaseCreator(QObject *parent) : QObject(parent)
{
    connectToDataBase();
    createTable();
}

bool DatabaseCreator::connectToDataBase()
{
    if (!QSqlDatabase::contains()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("weather_data_request.db");

        if (!db.open()) {
            qDebug() << "Ошибка подключения к базе данных:" << db.lastError();
            return false;
        }
    }
    qDebug() << "Успешное подключение к базе данных";
    return true;
}

void DatabaseCreator::createTable()
{
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS weather_data ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "username TEXT, "
                    "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP, "
                    "city TEXT, "
                    "date TEXT)")) {
        qDebug() << "Ошибка при создании таблицы:" << query.lastError();
    } else {
        qDebug() << "Таблица weather_data успешно создана или уже существует";
    }
}
