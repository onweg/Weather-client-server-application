import QtQuick 2.0
import Sailfish.Silica 1.0


Item {
    Column {
        anchors.centerIn: parent
        spacing: 10
        TextField {
            id: loginField
            placeholderText: "Login"
            width: parent.width
            color: "black"
        }
        TextField {
            id: passwordField
            placeholderText: "Password"
            echoMode: TextInput.Password
            width: parent.width
            color: "black"
        }
        Row {
            spacing: 10
            Button {
                text: "Log In"
                onClicked: {
                    authViewModel.loginUser(loginField.text, passwordField.text)
                }
            }
            Button {
                text: "Sign Up"
                onClicked: {
                    authViewModel.registerUser(loginField.text, passwordField.text)
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
        target: authViewModel
        onAuthSucceeded: {
            pageStack.push(Qt.resolvedUrl("../pages/WeatherPage.qml"));
        }
        onAuthFailed: {
            resultText.text = message;
        }
    }
}
