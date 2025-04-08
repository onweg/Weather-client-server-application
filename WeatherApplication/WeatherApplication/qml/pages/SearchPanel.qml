import QtQuick 2.0
import Sailfish.Silica 1.0

Item {    
    InputCity {
        id: search_city
        width: 530
        height: 130
        anchors.centerIn: parent
    }

    Button {
        width: 100
        text: "go"
        anchors.left: search_city.right
        anchors.verticalCenter: search_city.verticalCenter
        onClicked: {
            controller.getDataSearchCity(search_city.city);
        }
    }
}
