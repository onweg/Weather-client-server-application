#include "WeatherModeList.h"

WeatherModelList::WeatherModelList(QObject *parent)
    : QObject(parent)
{

}

void WeatherModelList::add(WeatherModel *model)
{
    m_list.append(model);
}

int WeatherModelList::count() const
{
    return m_list.size();
}

WeatherModel *WeatherModelList::get(int index) const
{
    if (index >= 0 && index < m_list.size())
        return m_list.at(index);
    return nullptr;
}
