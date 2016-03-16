import QtQuick 2.3
import QtQuick.Window 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1


//This class creates the three buttons
RowLayout {
    id: classSelection
    spacing : 2
    Layout.fillHeight: true
    Layout.fillWidth: true

    //base button
    Rectangle {
        id: uBaseClassButton
        color: "grey"
        Layout.preferredWidth:  parent.width /2
        Layout.preferredHeight: parent.height

        StyledText {
            text: "Class"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                setClassButton()
                uClassPanel.updateMethod()
            }
        }
    }

    //Interface button
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
                setInterfaceButton()
                uClassPanel.updateMethod()
            }
        }
    }

    function setInterfaceButton()
    {
        uInterfaceClassButton.color = 'grey'
        uBaseClassButton.color = 'white'
        dispatcher.setClassState(1)
        uClassPanel.disableParentField()
        uClassPanel.disableAbstractField()
    }

    function setClassButton()
    {
        uBaseClassButton.color = 'grey'
        uInterfaceClassButton.color = 'white'
        dispatcher.setClassState(0)
        uClassPanel.enableParentField()
        uClassPanel.enableAbstractField()
    }

}
