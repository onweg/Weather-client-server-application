import QtQuick 2.0
import Sailfish.Silica 1.0

Item {
    property alias city: search_city.text
    Rectangle {
        width: 500
        height: 57
        color: "lightgray"
        radius: 10
        anchors.centerIn: parent
        TextArea {
            id: search_city
            width: parent.width
            wrapMode: Text.NoWrap
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
