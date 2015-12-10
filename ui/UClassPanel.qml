import QtQuick 2.3
import QtQuick.Window 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.4

ColumnLayout {
    id: classPanel

    Label {
        Layout.fillHeight: true
        Layout.fillWidth: true

        StyledText {
            text: "Baseclass"
            horizontalAlignment: Text.AlignLeft
        }
    }

    TextField {
//        style: TextFieldStyle {
//                textColor: "black"
//                background: Rectangle {
//                    id: parentFieldBackground
//                    border.color: "black"
//                }
//            }
        id: parentField
        Layout.fillHeight: true
        Layout.fillWidth: true
        font.family: "Droid Sans"
        font.bold: false
        font.italic: false
        font.pointSize: 9
    }

    RowLayout {
        Layout.fillHeight: true
        Layout.fillWidth: true
        spacing: parent.width/4
        Label {
            width: parent.width*3/5
            Layout.fillHeight: true
            Layout.fillWidth: true
            StyledText {
                text: "Name"
                horizontalAlignment: Text.AlignLeft
            }
        }
        Label {
            width: parent.width/5
            Layout.fillHeight: true
            Layout.fillWidth: true
            //anchors.centerIn: xField
            StyledText {
                text: "X (0-"+(gridLayout.getWidth()-1)+")"
                horizontalAlignment: xField.Top
            }
        }
        Label {
            Layout.fillHeight: true
            width: parent.width/5
            Layout.fillWidth: true
            //anchors.centerIn: yField
            StyledText {
                text: "Y (0-" + (gridLayout.getHeight()-1) + ")"
                horizontalAlignment: yField.Top
            }
        }
    }

    RowLayout {
        Layout.fillHeight: true
        Layout.fillWidth: true
        spacing: parent.width/20
        TextField {
            id: nameField
            Layout.fillHeight: true
            Layout.fillWidth: true
            width: parent.width*3/5
            font.family: "Droid Sans"
            font.bold: false
            font.italic: false
            font.pointSize: 9
        }
        TextField {
            id: xField
            Layout.fillHeight: true
            Layout.fillWidth: true
            width: parent.width/5
            font.family: "Droid Sans"
            font.bold: false
            font.italic: false
            font.pointSize: 9
        }
        TextField {
            id: yField
            Layout.fillHeight: true
            Layout.fillWidth: true
            width: parent.width/5
            font.family: "Droid Sans"
            font.bold: false
            font.italic: false
            font.pointSize: 9
        }
    }

    Label {
        Layout.fillHeight: true
        Layout.fillWidth: true
        StyledText {
            text: "Methods"
            horizontalAlignment: Text.AlignLeft
        }
    }

    TextArea {
        id : methodField
        Layout.rowSpan: 3
        Layout.fillHeight: true
        Layout.fillWidth: true
        font.family: "Droid Sans"
        font.bold: false
        font.italic: false
        font.pointSize: 9
    }

    Label {
        Layout.fillHeight: true
        Layout.fillWidth: true
        StyledText {
            text: "Attributes"
            horizontalAlignment: Text.AlignLeft
        }
    }
    TextArea {
        id: attributeField
        Layout.rowSpan: 3
        Layout.fillHeight: true
        Layout.fillWidth: true
        font.family: "Droid Sans"
        font.bold: false
        font.italic: false
        font.pointSize: 9
    }

    RowLayout {
        spacing : 2
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.topMargin: 10
        Button {
            StyledText {
                text: "Create"
            }

            Layout.fillHeight: true
            Layout.fillWidth: true
            onClicked: {
                var coordX = xField.text
                var coordY = yField.text
                var name = nameField.text
                var parent = parentField.text
                var methods = methodField.text
                var attributes = attributeField.text

                if (parent != "" && dispatcher.getClassIndex(parent) === -1) {
                    parentField.textColor = "red"
                }
                else {
                    if (!gridLayout.contains(name) && gridLayout.isEmpty(parseInt(coordX), parseInt(coordY))) {
                        gridLayout.addClass(parseInt(coordX), parseInt(coordY), name)
                        dispatcher.createClass(name, parent, methods, attributes)
                        drawingCanvas.requestPaint()
                        clearTextFields()
                        drawingCanvas.selectedClass = ""
                    }
                    else if (!gridLayout.isEmpty(parseInt(coordX), parseInt(coordY))){
                        xField.textColor = "red"
                        yField.textColor = "red"
                    }
                    else{
                        nameField.textColor = "red"
                    }
                }
            }
        }
        Button {
            StyledText {
                text: "Update"
            }
            Layout.fillHeight: true
            Layout.fillWidth: true
            onClicked: {

                if (drawingCanvas.selectedClass != "") {
                    var i = xField.text
                    var j = yField.text
                    var name = nameField.text
                    var parent = parentField.text
                    var methods = methodField.text
                    var attributes = attributeField.text

                    gridLayout.moveClass(drawingCanvas.selectedClass, i, j)
                    dispatcher.updateClass(drawingCanvas.selectedClass, name, parent, methods, attributes)

                    drawingCanvas.requestPaint()
                    clearTextFields()
                    drawingCanvas.selectedClass = ""
                }
            }
        }
        Button {
            StyledText {
                text: "Delete"
            }

            Layout.fillHeight: true
            Layout.fillWidth: true
            onClicked: {
                var name = nameField.text
                if (name != "") {
                    if (gridLayout.contains(name)) {

                        dispatcher.removeClass(name)
                        gridLayout.removeClass(name)

                        drawingCanvas.requestPaint()
                        clearTextFields()
                        drawingCanvas.selectedClass = ""
                    }
                }
            }

        }
    }

    function clearTextFields() {
        xField.text = ""
        yField.text = ""
        nameField.text = ""
        parentField.text = ""
        methodField.text = ""
        attributeField.text = ""
    }

    function setInformation(x, y, name, parent, methods, attributes) {
        xField.text = x
        yField.text = y
        nameField.text = name
        parentField.text = parent
        methodField.text = methods
        attributeField.text = attributes
    }

    function setFieldsBlack(){
        xField.textColor = "black"
        yField.textColor = "black"
        nameField.textColor = "black"
        parentField.textColor = "black"
    }

    function disableParentField() {
        parentField.enabled = false
        //parentField.style.color = "grey"
    }

    function enableParentField() {
        parentField.enabled = true
        //parentFieldBackground.color = "white"
    }
}
