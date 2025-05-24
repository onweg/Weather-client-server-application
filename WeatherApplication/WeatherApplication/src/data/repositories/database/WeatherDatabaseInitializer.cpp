#include "WeatherDatabaseInitializer.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

QSqlDatabase WeatherDatabaseInitializer::initialize()
{
 QSqlDatabase db;

 if (QSqlDatabase::contains("qt_sql_default_connection"))
 {
  db = QSqlDatabase::database();
 }
 else
 {
  db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName(DB_PATH);

  if (!db.open())
  {
   qDebug() << "Ошибка подключения к БД:" << db.lastError();
   return {};
  }
 }

 if (!createTableIfNotExists(db))
 {
  qDebug() << "Не удалось создать таблицу.";
  return {};
 }

 return db;
}

bool WeatherDatabaseInitializer::createTableIfNotExists(QSqlDatabase &db)
{
 QSqlQuery query(db);
 bool ok = query.exec(R"(
  CREATE TABLE IF NOT EXISTS weather_data (
   id INTEGER PRIMARY KEY AUTOINCREMENT,
   username TEXT,
   timestamp DATETIME DEFAULT CURRENT_TIMESTAMP,
   city TEXT,
   date TEXT
  )
 )");

 if (!ok)
  qDebug() << "Ошибка при создании таблицы:" << query.lastError();

 return ok;
}
