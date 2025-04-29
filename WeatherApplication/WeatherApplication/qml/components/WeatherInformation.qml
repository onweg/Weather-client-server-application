import QtQuick 2.0
import ru.auroraos.weather 1.0


Item {
    id: root_info
    width: 470
    height: 780
    anchors.centerIn: parent
    Text {
        id: text_info
        text: qsTr("Информация о погоде в городе")
    }
    Text{
        id: weather_city
        font.pointSize: 40
        text: "..."
        anchors.top: text_info.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: text_info.horizontalCenter
    }
    DateAndButtons {
        id: date
        width: root_info.width
        anchors.top: weather_city.bottom
        anchors.topMargin: 50
    }
    WeatherData {
        id: weather_data
        // height: 460
        anchors.top: date.bottom
        anchors.topMargin: 80
    }
    Connections {
        target: controller
        onWeatherDataUpdated: {
            var data = controller.weatherModel;
            weather_city.text = data.city;
            date.date.text = data.date;
            weather_data.weather_description.text = data.description;
            weather_data.weather_feels_like.text = data.feelsLike;
            weather_data.weather_humidity.text = data.humidity;
            weather_data.weather_pressure.text = data.pressure;
            weather_data.weather_temp.text = data.temp;
            weather_data.weather_temp_max.text = data.tempMax;
            weather_data.weather_temp_min.text = data.tempMin;
            weather_data.weather_wind_speed.text = data.windSpeed;
            if (data.messageError.length > 0) {
                weather_data.weather_error.text = data.messageError;
                weather_data.weather_error.visible = true;
            } else {
                weather_data.weather_error.text = "";
                weather_data.weather_error.visible = false;
            }
        }
    }
}


