import QtQuick 2.0
import Sailfish.Silica 1.0

Item {
    Item {
        width: 645
        height: 75
        anchors.centerIn: parent
        InputCity {
            id: search_city
            width: 530
            height: 130
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
        }

        Button {
            width: 100
            text: "go"
            anchors.left: search_city.right
            anchors.verticalCenter: search_city.verticalCenter
            onClicked: {
                controller.clickSearchCityButton(search_city.city);
            }
        }
    }

}
