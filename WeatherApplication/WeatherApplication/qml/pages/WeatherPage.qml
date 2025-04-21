import QtQuick 2.0
import Sailfish.Silica 1.0
import "../components"


Page {

    SearchPanel {
        anchors.top: parent.top
        anchors.topMargin: 250
        anchors.horizontalCenter: parent.horizontalCenter

        // scale: 0.6
    }
    WeatherInformation {
        id: info
        width: 600
        height: 600
        anchors.centerIn: parent

        // scale: 0.6
    }

    Button {
        text: "показать на неделю"
        anchors.top: info.bottom
        anchors.topMargin: 100
        anchors.horizontalCenter: info.horizontalCenter
        onClicked: {
            pageStack.push(Qt.resolvedUrl("WeekWeatherPage.qml"));
            controller.clickWeekWeatherDataButton()
        }
    }
}
