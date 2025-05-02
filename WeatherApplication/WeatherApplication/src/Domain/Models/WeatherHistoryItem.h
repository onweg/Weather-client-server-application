#ifndef WEATHERHISTORYITEM_H
#define WEATHERHISTORYITEM_H

#include <QObject>
#include <QString>
#include <QDate>
#include <QDateTime>

 struct WeatherHistoryItem{
     int id = 0;
     QString username;
     QDateTime timestamp;
     QString city;
     QDate date;
 };

#endif // WEATHERHISTORYITEM_H
