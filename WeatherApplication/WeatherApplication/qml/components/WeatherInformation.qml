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
        anchors.topMargin: 30
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
            weather_city.text = controller.getCity();
            date.date.text = controller.getDate();
            weather_data.weather_description.text = controller.getDescription();
            weather_data.weather_feels_like.text = controller.getFeelsLike();
            weather_data.weather_humidity.text = controller.getHumidity();
            weather_data.weather_pressure.text = controller.getPressure();
            weather_data.weather_temp.text = controller.getTemp();
            weather_data.weather_temp_max.text = controller.getTempMax();
            weather_data.weather_temp_min.text = controller.getTempMin();
            weather_data.weather_wind_speed.text = controller.getWindSpeed();
        }
    }
}


