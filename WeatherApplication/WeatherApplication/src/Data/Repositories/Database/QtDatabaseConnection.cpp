#include "QtDatabaseConnection.h"

#include <QSqlError>

QtDatabaseConnection::QtDatabaseConnection(QSqlDatabase db) : db_(std::move(db))
{
}

bool QtDatabaseConnection::isOpen() const
{
	return db_.isOpen();
}

std::string QtDatabaseConnection::getLastError() const
{
	return db_.lastError().text().toStdString();
}

QSqlDatabase QtDatabaseConnection::getQtDatabase() const
{
	return db_;
}
