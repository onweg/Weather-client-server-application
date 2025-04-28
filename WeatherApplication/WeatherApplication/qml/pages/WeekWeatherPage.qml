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
        Column {
            Text {
                id: text_error
                text: ""
                color: "red"
                visible: false;
            }
            
        }
        anchors.centerIn: parent
    }
    Connections {
        target: controller
        onWeekDataUpdated: {
            var data = controller.getWeatherDataFromWeek();
            var dailyWeather = data["dailyWeather"];
            today_date.text = "Date: " + (dailyWeather[0] ? dailyWeather[0]["date"] : "No data");
            today_temp.text = "Temp: " + (dailyWeather[0] ? dailyWeather[0]["temp"] : "No data");
            tomorrow_date.text = "Date: " + (dailyWeather[1] ? dailyWeather[1]["date"] : "No data");
            tomorrow_temp.text = "Temp: " + (dailyWeather[1] ? dailyWeather[1]["temp"] : "No data");
            after_tomorrow_date.text = "Date: " + (dailyWeather[2] ? dailyWeather[2]["date"] : "No data");
            after_tomorrow_temp.text = "Temp: " + (dailyWeather[2] ? dailyWeather[2]["temp"] : "No data");
            today_plus_3_date.text = "Date: " + (dailyWeather[3] ? dailyWeather[3]["date"] : "No data");
            today_plus_3_temp.text = "Temp: " + (dailyWeather[3] ? dailyWeather[3]["temp"] : "No data");
            today_plus_4_date.text = "Date: " + (dailyWeather[4] ? dailyWeather[4]["date"] : "No data");
            today_plus_4_temp.text = "Temp: " + (dailyWeather[4] ? dailyWeather[4]["temp"] : "No data");
            if (data["messageError"] && data["messageError"].length > 0) {
                text_error.text = "Error: " + data["messageError"];
                text_error.visible = true;
            } else {
                text_error.text = "";
                text_error.visible = false;
            }
        }
    }
}
