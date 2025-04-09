import QtQuick 2.0

Item {
    property alias weather_description: weather_description
    property alias weather_temp: weather_temp
    property alias weather_feels_like: weather_feels_like
    property alias weather_temp_max: weather_temp_max
    property alias weather_temp_min: weather_temp_min
    property alias weather_wind_speed: weather_wind_speed
    property alias weather_humidity: weather_humidity
    property alias weather_pressure: weather_pressure
    Row {
        spacing: 20
        Column {
            spacing: 30
            Text {
                text: "описание"
            }
            Text {
                text: "температура"
            }
            Text {
                text: "чувствуется как"
            }
            Text {
                text: "макс температура"
            }
            Text {
                text: "мин температура"
            }
            Text {
                text: "скорость ветра"
            }
            Text {
                text: "влажность"
            }
            Text {
                text: "давление"
            }
        }
        Column {
            spacing: 30
            Text {
                id: weather_description
                text: "..."
            }
            Row {
                Text {
                    id: weather_temp
                    text: "0.0"
                }
                Text {
                    text: " °C"
                }
            }
            Row {
                Text {
                    id: weather_feels_like
                    text: "0.0"
                }
                Text {
                    text: " °C"
                }
            }

            Row {
                Text {
                    id: weather_temp_max
                    text: "0.0"
                }
                Text {
                    text: " °C"
                }
            }

            Row {
                Text {
                    id: weather_temp_min
                    text: "0.0"
                }
                Text {
                    text: " °C"
                }
            }

            Row {
                Text {
                    id: weather_wind_speed
                    text: "0.0"
                }
                Text {
                    text: " м/с"
                }
            }
            Row {
                Text {
                    id: weather_humidity
                    text: "0"
                }
                Text {
                    text: " г/м^3"
                }
            }

            Row {
                Text {
                    id: weather_pressure
                    text: "0"
                }
                Text {
                    text: " Па"
                }
            }
        }
    }
}
