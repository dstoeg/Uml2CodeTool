import QtQuick 2.3
import QtQuick.Window 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1

MenuBar {
    id: mainMenuBar
    Menu {

        title: "File"

        MenuItem {
            text: "Open..."
        }

        MenuItem {
            text: "Close"
        }
    }

    Menu {
        title: "Edit"

        MenuItem {
            text: "Cut"
        }

        MenuItem {
            text: "Copy"
        }

        MenuItem {
            text: "Paste"
        }
    }

    Menu {
        title: "Code"

        MenuItem {
            text: "Generate"
            onTriggered: {
                var component = Qt.createComponent("UCodeGenerationDialogue.qml");
                win = component.createObject(mainMenuBar);
                win.show();
            }
        }
    }

    Menu {
        title: "Help"

    }

    Menu {
        title: "About"
    }
}

