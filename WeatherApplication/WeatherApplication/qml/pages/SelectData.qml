import QtQuick 2.0
import Sailfish.Silica 1.0

Item {    
    SelectCountry {
        id:select_country
        width: 250
        height: 130

        anchors.right: select_city.left
        anchors.verticalCenter: select_city.verticalCenter
    }
    SelectCity {
        id: select_city
        width: 250
        height: 130
        anchors.centerIn: parent
    }
    Button {
        width: 200
        text: "go"
        anchors.left: select_city.right
        anchors.verticalCenter: select_city.verticalCenter
        onClicked: {
            controller.getDataFromQML(select_country.country + '*' + select_city.cityCode);
        }
    }
}
