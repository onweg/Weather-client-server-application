import QtQuick 2.0

Item {

    Text {
        id: lbl_info
        text: "Information about the weather in Moscow"
    }
    DateAndButtons {
        id: date
        anchors.top: lbl_info.bottom
        anchors.topMargin: 20
    }

    WeatherData {
        height: 460
        anchors.top: date.bottom
        anchors.topMargin: 80

    }

}
