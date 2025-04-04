#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>

// работает с базой данных
// хранит историю прогноза погоды

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = nullptr);

signals:

};

#endif // DATABASEMANAGER_H
