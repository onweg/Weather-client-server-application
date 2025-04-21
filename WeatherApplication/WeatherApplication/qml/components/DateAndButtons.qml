import QtQuick 2.0
import Sailfish.Silica 1.0

Item {
    property alias date: date
    width: parent
    // spacing: 50
    Button {
        width: 70
        text: "<-"
        onClicked: {
            controller.clickPrevDayButton();
        }
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
    }
    Text {
        id: date
        text: "..."
        font.pixelSize: 40
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

    }
    Button {
        width: 70
        text: "->"
        onClicked: {
            controller.clickNextDayButton();
        }
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
    }
}
