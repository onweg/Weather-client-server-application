import QtQuick 2.0
import Sailfish.Silica 1.0
import "../components"
import ru.auroraos.weather 1.0

Page {
    Text {
        text: "Погода на неделю в городе " + controller.weekWeatherModel.city;
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
        onWeekWeatherDataUpdated: {
            var data = controller.weekWeatherModel
            var list = data.dailyWeather;
            console.log("dailyWeather type:", typeof list);
            console.log("dailyWeather length:", list.count());
            console.log("dailyWeather contents:", list);
            console.log("has count():", typeof list.count === 'function'); // true
            console.log("has get():", typeof list.get === 'function');     // true
            console.log("has length:", 'length' in list);                  // false
            var len = list.count();
            today_date.text = "Date: " + (len > 0 ? list.get(0).date : "No Data");
            today_temp.text = "Temp: " + (len > 0 ? list.get(0).temp : "No Data");
            tomorrow_date.text = "Date: " + (len > 1 ? list.get(1).date : "No Data");
            tomorrow_temp.text = "Temp: " + (len > 1 ? list.get(1).temp : "No Data");
            after_tomorrow_date.text = "Date: " + (len > 2 ? list.get(2).date : "No Data");
            after_tomorrow_temp.text = "Temp: " + (len > 2 ? list.get(2).temp : "No Data");
            today_plus_3_date.text = "Date: " + (len > 3 ? list.get(3).date : "No Data");
            today_plus_3_temp.text = "Temp: " + (len > 3 ? list.get(3).temp : "No Data");
            today_plus_4_date.text = "Date: " + (len > 4 ? list.get(4).date : "No Data");
            today_plus_4_temp.text = "Temp: " + (len > 4 ? list.get(4).temp : "No Data");
            if (data.messageError && data.messageError.length > 0) {
                text_error.text = "Error: " + data.messageError;
                text_error.visible = true;
            } else {
                text_error.text = "";
                text_error.visible = false;
            }
        }
    }
}
