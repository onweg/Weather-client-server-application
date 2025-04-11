#ifndef DATAEDITOR_H
#define DATAEDITOR_H

#include <QObject>
#include <QJsonObject>

class DataEditor : public QObject
{
    Q_OBJECT
public:
    explicit DataEditor(QObject *parent = nullptr);
    QJsonObject getCorrectData(QJsonObject jsonObj);

signals:

};

#endif // DATAEDITOR_H
