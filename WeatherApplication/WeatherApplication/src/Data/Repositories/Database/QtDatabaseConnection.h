#ifndef QTDATABASECONNECTION_H
#define QTDATABASECONNECTION_H

#include "../../../Domain/Interfaces/Database/IWeatherDatabaseConnection.h"
#include <QSqlDatabase>

class QtDatabaseConnection : public IWeatherDatabaseConnection {
public:
    explicit QtDatabaseConnection(QSqlDatabase db);

    bool isOpen() const override;
    std::string getLastError() const override;

    QSqlDatabase getQtDatabase() const; // Для внутреннего использования

private:
    QSqlDatabase db_;
};

#endif // QTDATABASECONNECTION_H
