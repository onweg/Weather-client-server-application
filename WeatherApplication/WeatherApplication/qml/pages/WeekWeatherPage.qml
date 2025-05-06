import QtQuick 2.0
import Sailfish.Silica 1.0
import "../components"

Page {
    Text {
        text: "Погода на неделю в городе " + weatherViewModel.weekWeatherModel.city
        anchors.top: parent.top
        anchors.topMargin: 50
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Column {
        spacing: 40
        anchors.centerIn: parent

        Column {
            spacing: 20
            Text { text: "Date: " + (weatherViewModel.weekWeatherModel.dailyWeather.length > 0 ? weatherViewModel.weekWeatherModel.dailyWeather[0].date : "No Data") }
            Text { text: "Temp: " + (weatherViewModel.weekWeatherModel.dailyWeather.length > 0 ? weatherViewModel.weekWeatherModel.dailyWeather[0].temp : "No Data") }
        }

        Column {
            spacing: 20
            Text { text: "Date: " + (weatherViewModel.weekWeatherModel.dailyWeather.length > 1 ? weatherViewModel.weekWeatherModel.dailyWeather[1].date : "No Data") }
            Text { text: "Temp: " + (weatherViewModel.weekWeatherModel.dailyWeather.length > 1 ? weatherViewModel.weekWeatherModel.dailyWeather[1].temp : "No Data") }
        }

        Column {
            spacing: 20
            Text { text: "Date: " + (weatherViewModel.weekWeatherModel.dailyWeather.length > 2 ? weatherViewModel.weekWeatherModel.dailyWeather[2].date : "No Data") }
            Text { text: "Temp: " + (weatherViewModel.weekWeatherModel.dailyWeather.length > 2 ? weatherViewModel.weekWeatherModel.dailyWeather[2].temp : "No Data") }
        }

        Column {
            spacing: 20
            Text { text: "Date: " + (weatherViewModel.weekWeatherModel.dailyWeather.length > 3 ? weatherViewModel.weekWeatherModel.dailyWeather[3].date : "No Data") }
            Text { text: "Temp: " + (weatherViewModel.weekWeatherModel.dailyWeather.length > 3 ? weatherViewModel.weekWeatherModel.dailyWeather[3].temp : "No Data") }
        }

        Column {
            spacing: 20
            Text { text: "Date: " + (weatherViewModel.weekWeatherModel.dailyWeather.length > 4 ? weatherViewModel.weekWeatherModel.dailyWeather[4].date : "No Data") }
            Text { text: "Temp: " + (weatherViewModel.weekWeatherModel.dailyWeather.length > 4 ? weatherViewModel.weekWeatherModel.dailyWeather[4].temp : "No Data") }
        }

        Text {
            id: text_error
            text: weatherViewModel.weekWeatherModel.messageError.length > 0 ? "Error: " + weatherViewModel.weekWeatherModel.messageError : ""
            color: "red"
            visible: weatherViewModel.weekWeatherModel.messageError.length > 0
        }
    }
}
