import QtQuick 2.0
import Sailfish.Silica 1.0

Item {
    anchors.fill: parent
    Column {
        anchors.centerIn: parent
        spacing: 10

        TextField {
            id: loginField
            placeholderText: "Login"
            width: parent.width * 0.8
            color: "black"
            inputMethodHints: Qt.ImhNoAutoUppercase | Qt.ImhNoPredictiveText
        }

        TextField {
            id: passwordField
            placeholderText: "Password"
            echoMode: TextInput.Password
            width: parent.width * 0.8
            color: "black"
            inputMethodHints: Qt.ImhNoAutoUppercase | Qt.ImhNoPredictiveText
        }

        Row {
            spacing: 10

            Button {
                text: "Log In"
                onClicked: {
                    controller.sendAuthorizationData("LOGIN", loginField.text, passwordField.text)
                }
            }

            Button {
                text: "Sign Up"
                onClicked: {
                    controller.sendAuthorizationData("REGISTER", loginField.text, passwordField.text)
                }
            }
        }

        Text {
            id: resultText
            width: parent.width * 0.9
            wrapMode: Text.WordWrap
            color: "black"
        }
    }

    Connections {
        target: controller
        onAuthorizationCompleted: {
            pageStack.push(Qt.resolvedUrl("WeatherPage.qml"));
        }
        onAuthorizationFailed: {
            resultText.text = message;
        }
    }
}
