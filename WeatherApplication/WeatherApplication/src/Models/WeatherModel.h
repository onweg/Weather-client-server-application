

class WeatherModel : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString city READ city NOTIFY dataChanged)
    

public:
    WeatherModel(QObject* parent = nullptr);

    QString city() const;

    void setData(const WeatherData& data); // загрузка модели из бизнес-данных

signals:
    void dataChanged();

private:
    WeatherData m_data;
};
