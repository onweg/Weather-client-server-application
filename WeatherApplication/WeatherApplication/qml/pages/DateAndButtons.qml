import QtQuick 2.0
import Sailfish.Silica 1.0

Item {
    property alias date: date
    Row {
        spacing: 50
        Button {
            width: 70
            text: "<-"
            onClicked: {
                controller.clickPrevDayButton();
            }
        }
        Text {
            id: date
            text: "..."
            font.pixelSize: 40
        }
        Button {
            width: 70
            text: "->"
            onClicked: {
                controller.clickNextDayButton();
            }
        }
    }
}
