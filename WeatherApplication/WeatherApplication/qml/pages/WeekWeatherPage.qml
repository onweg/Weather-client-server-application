import QtQuick 2.0
import Sailfish.Silica 1.0
import "../components"

Page {
    Text {
        text: "Погода на неделю в городе " + controller.getCity();
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
            today_date.text = "Date: " + controller.getDateFromWeek(0);
            today_temp.text = "Temp: " + controller.getTempFromWeek(0);
            tomorrow_date.text = "Date: " + controller.getDateFromWeek(1);
            tomorrow_temp.text = "Temp: " + controller.getTempFromWeek(1);
            after_tomorrow_date.text = "Date: " + controller.getDateFromWeek(2);
            after_tomorrow_temp.text = "Temp: " + controller.getTempFromWeek(2);
            today_plus_3_date.text = "Date: " + controller.getDateFromWeek(3);
            today_plus_3_temp.text = "Temp: " + controller.getTempFromWeek(3);
            today_plus_4_date.text = "Date: " + controller.getDateFromWeek(4);
            today_plus_4_temp.text = "Temp: " + controller.getTempFromWeek(4);
        }
    }
}
