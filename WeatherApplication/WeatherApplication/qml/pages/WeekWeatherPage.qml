import QtQuick 2.0
import Sailfish.Silica 1.0
import "../components"

Page {
    Text {
        text: "Погода на неделю в городе " + controller.getWeatherDataFromOneDay()["city"];
        anchors.top: parent.top;
        anchors.topMargin: 50
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Column {
        spacing: 40
        Column {
            spacing: 20
            Text {
                id: today_date
                text: "Date: "
            }
            Text {
                id: today_temp
                text: "Temp: "
            }
        }

        Column {
            spacing: 20
            Text {
                id: tomorrow_date
                text: "Date: "
            }
            Text {
                id: tomorrow_temp
                text: "Temp: "
            }
        }

        Column {
            spacing: 20
            Text {
                id: after_tomorrow_date
                text: "Date: "
            }
            Text {
                id: after_tomorrow_temp
                text: "Temp: "
            }
        }

        Column {
            spacing: 20
            Text {
                id: today_plus_3_date
                text: "Date: "
            }
            Text {
                id: today_plus_3_temp
                text: "Temp: "
            }
        }

        Column {
            spacing: 20
            Text {
                id: today_plus_4_date
                text: "Date: "
            }
            Text {
                id: today_plus_4_temp
                text: "Temp: "
            }
        }
        anchors.centerIn: parent
    }
    Connections {
        target: controller
        onWeekDataUpdated: {
            today_date.text = "Date: " + controller.getWeatherDataFromWeek()["0"]["date"];
            today_temp.text = "Temp: " + controller.getWeatherDataFromWeek()["0"]["temp"];
            tomorrow_date.text = "Date: " + controller.getWeatherDataFromWeek()["1"]["date"];
            tomorrow_temp.text = "Temp: " + controller.getWeatherDataFromWeek()["1"]["temp"];
            after_tomorrow_date.text = "Date: " + controller.getWeatherDataFromWeek()["2"]["date"];
            after_tomorrow_temp.text = "Temp: " + controller.getWeatherDataFromWeek()["2"]["temp"];
            today_plus_3_date.text = "Date: " + controller.getWeatherDataFromWeek()["3"]["date"];
            today_plus_3_temp.text = "Temp: " + controller.getWeatherDataFromWeek()["3"]["temp"];
            today_plus_4_date.text = "Date: " + controller.getWeatherDataFromWeek()["4"]["date"];
            today_plus_4_temp.text = "Temp: " + controller.getWeatherDataFromWeek()["4"]["temp"];
        }
    }
}
