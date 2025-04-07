import QtQuick 2.0
import Sailfish.Silica 1.0

Item {
    property alias cityCode: input_city_code.text
    Column {
        spacing: 10
        Label {
            id: lbl_city_code
            text: "City code"
        }
        Rectangle {
            width: lbl_city_code.width * 1.4
            height: lbl_city_code.height * 1.4
            color: "lightgray"
            radius: 10
            anchors.horizontalCenter: lbl_city_code.horizontalCenter
            TextArea {
                id: input_city_code
                width: parent.width * 1.5
                anchors.top: parent.top
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }


}
