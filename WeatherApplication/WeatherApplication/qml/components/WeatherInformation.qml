import QtQuick 2.0


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
        onDataUpdated: {
            weather_city.text = controller.getWeatherDataFromOneDay()["city"];
            date.date.text = controller.getWeatherDataFromOneDay()["date"];
            weather_data.weather_description.text = controller.getWeatherDataFromOneDay()["description"];
            weather_data.weather_feels_like.text = controller.getWeatherDataFromOneDay()["feels_like"];
            weather_data.weather_humidity.text = controller.getWeatherDataFromOneDay()["humidity"];
            weather_data.weather_pressure.text = controller.getWeatherDataFromOneDay()["pressure"];
            weather_data.weather_temp.text = controller.getWeatherDataFromOneDay()["temp"];
            weather_data.weather_temp_max.text = controller.getWeatherDataFromOneDay()["temp_max"];
            weather_data.weather_temp_min.text = controller.getWeatherDataFromOneDay()["temp_min"];
            weather_data.weather_wind_speed.text = controller.getWeatherDataFromOneDay()["wind_speed"];
        }
    }
}


