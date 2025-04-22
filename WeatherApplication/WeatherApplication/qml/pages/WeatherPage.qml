import QtQuick 2.0
import Sailfish.Silica 1.0
import "../components"


Page {
    SearchPanel {
        anchors.top: parent.top
        anchors.topMargin: 250
        anchors.horizontalCenter: parent.horizontalCenter
    }
    WeatherInformation {
        id: info
        anchors.centerIn: parent
    }
    Button {
        text: "показать на неделю"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 250
        anchors.horizontalCenter: info.horizontalCenter
        onClicked: {
            pageStack.push(Qt.resolvedUrl("WeekWeatherPage.qml"));
            controller.clickWeekWeatherDataButton()
        }
    }
}
