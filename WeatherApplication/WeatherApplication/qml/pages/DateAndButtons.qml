import QtQuick 2.0
import Sailfish.Silica 1.0

Item {
    Row {
        spacing: 50
        Button {
            text: "<- prev day"
        }
        Text {
            text: "08.04.25"
            font.pixelSize: 40
        }
        Button {
            text: "next day ->"
        }
    }
}
