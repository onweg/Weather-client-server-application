#include "databasemanager.h"

DatabaseManager::DatabaseManager(QObject *parent) : QObject(parent)
{

}

void DatabaseManager::slotSubmitCompletedWeatherDataSearchRequest(const QString &user, const QDateTime &timestamp, const QString &city, const QDate &date, const QJsonObject &jsonObj)
{

}
