import QtQuick 2.0

Item {

    Connections {
        target: controller
        onDataUpdated: {
            weather_description.text = controller.getDescription();
            weather_feels_like.text = controller.getFeelsLike();
            weather_humidity.text = controller.getHumidity();
            weather_pressure.text = controller.getPressure();
            weather_temp.text = controller.getTemp();
            weather_temp_max.text = controller.getTempMax();
            weather_temp_min.text = controller.getTempMin();
            weather_wind_speed.text = controller.getWindSpeed();
        }
    }

    Row {
        spacing: 20
        Column {
            spacing: 30
            Text {
                text: "description"
            }
            Text {
                text: "temp"
            }
            Text {
                text: "feels_like"
            }
            Text {
                text: "temp_max"
            }
            Text {
                text: "temp_min"
            }
            Text {
                text: "wind_speed"
            }
            Text {
                text: "humidity"
            }
            Text {
                text: "pressure"
            }
        }
        Column {
            spacing: 30
            Text {
                id: weather_description
                text: "небольшой снег"
            }
            Text {
                id: weather_temp
                text: "7 °C"
            }
            Text {
                id: weather_feels_like
                text: "7.7 °C"
            }
            Text {
                id: weather_temp_max
                text: "8 °C"
            }
            Text {
                id: weather_temp_min
                text: "5.2 °C"
            }
            Text {
                id: weather_wind_speed
                text: "20 м/c"
            }
            Text {
                id: weather_humidity
                text: "70"
            }
            Text {
                id: weather_pressure
                text: "1"
            }
        }
    }

}
