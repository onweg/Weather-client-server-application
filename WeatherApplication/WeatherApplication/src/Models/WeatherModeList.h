#ifndef WEATHERMODELLIST_H
#define WEATHERMODELLIST_H

#include <QObject>
#include <QList>
#include "WeatherModel.h"

class WeatherModelList : public QObject
{
    Q_OBJECT

public:
    explicit WeatherModelList(QObject *parent = nullptr);
    void add(WeatherModel* model);

    Q_INVOKABLE int count() const;
    Q_INVOKABLE WeatherModel* get(int index) const;

private:
    QList<WeatherModel*> m_list;
};

#endif // WEATHERMODELLIST_H
