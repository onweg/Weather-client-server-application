import QtQuick 2.0
//import ru.auroraos.weather 1.0


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
        text: weatherViewModel.weatherModel.city
        anchors.top: text_info.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: text_info.horizontalCenter
    }
    DateAndButtons {
        id: date
        width: root_info.width
        date.text: weatherViewModel.weatherModel.date
        anchors.top: weather_city.bottom
        anchors.topMargin: 50
    }
    WeatherData {
        id: weather_data
        anchors.top: date.bottom
        anchors.topMargin: 80
        weather_description.text: weatherViewModel.weatherModel.description
        weather_temp.text: weatherViewModel.weatherModel.temp
        weather_feels_like.text: weatherViewModel.weatherModel.feelsLike
        weather_temp_max.text: weatherViewModel.weatherModel.tempMax
        weather_temp_min.text: weatherViewModel.weatherModel.tempMin
        weather_wind_speed.text: weatherViewModel.weatherModel.windSpeed
        weather_humidity.text: weatherViewModel.weatherModel.humidity
        weather_pressure.text: weatherViewModel.weatherModel.pressure
        weather_error.text: weatherViewModel.weatherModel.messageError
        weather_error.visible: weatherViewModel.weatherModel.messageError.length > 0
    }
}


