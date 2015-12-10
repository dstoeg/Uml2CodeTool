import QtQuick 2.3
import QtQuick.Window 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.0

ApplicationWindow {
    id: root
    visible: true
    width: 700
    height: 500
    title: "Code Generation"
    color:  "white"


    ColumnLayout {
        Layout.margins: 20
        anchors.fill: parent

        RowLayout {
            Layout.margins: 20
            Layout.fillHeight: true
            Layout.fillWidth: true
            Label {
                Layout.fillHeight: true
                Layout.fillWidth: true
                StyledText {
                    text: "Language"
                    horizontalAlignment: Text.AlignLeft
                }
            }
            ComboBox {
                id: languageCB
                model: [ "None", "C++", "Java", "Python" ]
                onCurrentIndexChanged: {
                    dispatcher.setLanguage(languageCB.currentText);
                }
            }
        }

        RowLayout {
            Layout.margins: 20
            Layout.fillHeight: true
            Layout.fillWidth: true
            Label {
                Layout.fillHeight: true
                Layout.fillWidth: true
                StyledText {
                    text: "Folder"
                    horizontalAlignment: Text.AlignLeft
                }
            }
            Button {
                StyledText {
                    text: "Choose Folder"
                }
                onClicked: {
                    var component = Qt.createComponent("UFileDialog.qml");
                    var win2 = component.createObject(generationDialog);
                    win2.show();
                }
            }
        }

        RowLayout {
            Layout.margins: 20
            Layout.fillHeight: true
            Layout.fillWidth: true
            Label {
                Layout.fillHeight: true
                Layout.fillWidth: true
                StyledText {
                    text: "Project File"
                    horizontalAlignment: Text.AlignLeft
                }
            }
            ComboBox {
                model: [ "None", "Visual Studio", "QtCreator" ]
            }
        }

        RowLayout {
            Layout.margins: 20
            Layout.fillHeight: true
            Layout.fillWidth: true
            Label {
                Layout.fillHeight: true
                Layout.fillWidth: true
                StyledText {
                    text: "Doxygen Comments"
                    horizontalAlignment: Text.AlignLeft
                }
            }
            CheckBox {
                checked: false
            }
        }

        RowLayout {
            Layout.margins: 20
            Layout.fillHeight: true
            Layout.fillWidth: true
            Button {
                StyledText {
                    text: "Cancel"
                }
                onClicked: {
                    close()
                }

            }
            Button {
                StyledText {
                    text: "Generate"
                }
                onClicked: {
                    //TODO
                    dispatcher.generateCode()
                    close()
                }
            }
        }


    }
}

