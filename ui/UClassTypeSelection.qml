import QtQuick 2.3
import QtQuick.Window 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1

RowLayout {
    spacing : 2
    Layout.fillHeight: true
    Layout.fillWidth: true

    Rectangle {
        id: uBaseClassButton
        color: "white"
        Layout.preferredWidth:  parent.width /3
        Layout.preferredHeight: parent.height

        StyledText {
            text: "Base"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                parent.color = 'grey'
                uInterfaceClassButton.color = 'white'
                uChildClassButton.color = "white"
                dispatcher.setClassState(0)
            }
        }
    }

    Rectangle {
        id: uInterfaceClassButton
        color: "white"
        Layout.fillHeight: true
        Layout.fillWidth: true

        StyledText {
            text: "Interface"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                parent.color = 'grey'
                uBaseClassButton.color = 'white'
                uChildClassButton.color = "white"
                dispatcher.setClassState(1)
            }
        }
    }

    Rectangle {
        id: uChildClassButton
        color: "white"
        Layout.fillHeight: true
        Layout.fillWidth: true

        StyledText {
            text: "Child"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                parent.color = 'grey'
                uBaseClassButton.color = 'white'
                uInterfaceClassButton.color = "white"
                dispatcher.setClassState(2)
            }
        }
    }


}
