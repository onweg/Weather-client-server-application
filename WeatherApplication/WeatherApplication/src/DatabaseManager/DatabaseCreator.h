#ifndef DATABASECREATOR_H
#define DATABASECREATOR_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class DatabaseCreator : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseCreator(QObject *parent = nullptr);
    bool connectToDataBase();
    void createTable();

private:
    QSqlDatabase db;
};

#endif // DATABASECREATOR_H
