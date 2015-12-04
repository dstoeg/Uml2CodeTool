import QtQuick 2.3
import QtQuick.Window 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1


ApplicationWindow {
    visible: true
    width: 1600
    height: 900
    title: "uCode"
    color:  "white"

    menuBar : UMenuBar {

    }

    RowLayout {
        id: mainWindow
        anchors.fill: parent
        spacing: 5


        UDrawingCanvas {
            Layout.preferredWidth: parent.width * 0.75
            Layout.preferredHeight: parent.height
        }

        ColumnLayout {
            id: sideWindow
            spacing : 5
            Layout.preferredWidth: parent.width * 0.25
            Layout.preferredHeight: parent.height
            Layout.margins: 10
            Layout.leftMargin: 5

            UClassTypeSelection {
                Layout.preferredWidth: parent.width
                Layout.preferredHeight: parent.height * 0.05
            }

            UClassPanel {
                Layout.preferredWidth: parent.width
                Layout.preferredHeight: parent.height * 0.95
            }
        }
    }
}
