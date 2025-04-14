import QtQuick 2.0
import Sailfish.Silica 1.0


Page {
    SearchPanel {
        anchors.top: parent.top
        anchors.topMargin: 250
        anchors.horizontalCenter: parent.horizontalCenter

        // scale: 0.6
    }
    WeatherInformation {
        width: 600
        height: 600
        anchors.centerIn: parent

        // scale: 0.6
    }
}
