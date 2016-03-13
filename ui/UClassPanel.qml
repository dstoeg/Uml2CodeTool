import QtQuick 2.3
import QtQuick.Window 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.4

ColumnLayout {
    id: classPanel

    Label {
        id: inheritLabel
        Layout.fillHeight: true
        Layout.fillWidth: true

        StyledText {
            text: "Inherits from"
            horizontalAlignment: Text.AlignLeft
        }
    }

    RowLayout{
        TextField {
            id: parentField
            Layout.fillHeight: true
            Layout.fillWidth: true
            font.family: "Droid Sans"
            font.bold: false
            font.italic: false
            font.pointSize: 9
            enabled: true
            onTextChanged: {
                updateMethod();
            }
            onActiveFocusChanged: {
                if(activeFocus == true)
                    drawingCanvas.selectingParent = true;
                else
                    drawingCanvas.selectingParent = false;
            }
            Keys.onReturnPressed: {
                createMethod()
                event.accepted = true;
            }
        }

        CheckBox {
            id: abstractField;
            Layout.fillWidth: false
            text: qsTr("Abstract")
            onCheckedChanged: updateMethod()
        }
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
                text: "Class"
                horizontalAlignment: Text.AlignLeft
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
            onTextChanged: updateMethod()
            Keys.onReturnPressed: {
                createMethod()
                event.accepted = true;
            }
        }
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
        id : attributeField
        Layout.rowSpan: 3
        Layout.fillHeight: true
        Layout.fillWidth: true
        font.family: "Droid Sans"
        font.bold: false
        font.italic: false
        font.pointSize: 9
        onTextChanged: updateMethod()
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
        id: methodField
        Layout.rowSpan: 3
        Layout.fillHeight: true
        Layout.fillWidth: true
        font.family: "Droid Sans"
        font.bold: false
        font.italic: false
        font.pointSize: 9
        onTextChanged: updateMethod()
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
                createMethod();
            }
        }

        Button {
            StyledText {
                text: "Delete"
            }

            Layout.fillHeight: true
            Layout.fillWidth: true
            onClicked: {
                deleteMethod()
            }
        }
    }

    function clearTextFields() {
        drawingCanvas.selectedClass = ""
        nameField.text = ""
        parentField.text = ""
        methodField.text = ""
        attributeField.text = ""
        abstractField.checked = false;
    }

    function setInformation(name, parent, methods, attributes, isAbstract, isInterface) {
        nameField.text = name
        parentField.text = parent
        methodField.text = methods
        attributeField.text = attributes

        if(isAbstract)
            abstractField.checked = true;
        if(isInterface)
            uClassSelection.setInterfaceButton()
        else
            uClassSelection.setClassButton()

    }

    function setParentField(name)
    {
        parentField.text = name
        nameField.forceActiveFocus();
    }

    function setFieldsBlack(){
        nameField.textColor = "black"
        parentField.textColor = "black"
    }

    function disableParentField() {
        parentField.enabled = false
        parentField.visible = false
        inheritLabel.visible = false
    }

    function enableParentField() {
        parentField.enabled = true
        parentField.visible = true
        inheritLabel.visible = true
    }

    function disableAbstractField()
    {
        abstractField.enabled = false
        abstractField.visible = false
    }

    function enableAbstractField()
    {
        abstractField.enabled = true
        abstractField.visible = true
    }

    function updateMethod()
    {
        if (drawingCanvas.selectedClass != "" && !drawingCanvas.selecting) {

            var name = nameField.text
            var parent = parentField.text
            var methods = methodField.text
            var attributes = attributeField.text
            var isAbstract = abstractField.checked


            //Move the class in the grid
            gridLayout.changeObjectName(drawingCanvas.selectedClass, name)

            //Check if the class has a parent
            if(parent != "")
                dispatcher.setClassState(2)

            //Update the class
            dispatcher.updateClass(drawingCanvas.selectedClass, name, parent, methods, attributes, isAbstract)

            //Repaint the canvas
            drawingCanvas.requestPaint()
        }
    }

    function createMethod()
    {
        var name = nameField.text
        var parent = parentField.text
        var methods = methodField.text
        var attributes = attributeField.text
        var isAbstract = abstractField.checked;


        if (parent != "" && dispatcher.getClassIndex(parent) === -1) {
            parentField.textColor = "red"
        }
        else {
            if (name != "" && !gridLayout.contains(name)) {

                //Add the class to the grid
                gridLayout.addClass(Number(10),Number(10),drawingCanvas.getClassWidth(),drawingCanvas.getClassHeight(), name)

                //Check if the class has a parent
                if(parent != "")
                    dispatcher.setClassState(2)

                //Create the class
                dispatcher.createClass(name, parent, methods, attributes, isAbstract)

                //Repaint the canvas
                drawingCanvas.requestPaint()
                clearTextFields()
                drawingCanvas.selectedClass = ""
            }
            else if (!gridLayout.isEmpty(Number(10), Number(10))){
                //TODO notify space not empty
                uDebugger.qPrintText("Position (0,0) not Empty");
            }
            else{
                nameField.textColor = "red"
            }
        }
    }

    function deleteMethod()
    {
        var name = nameField.text
        if (name != "") {
            if (gridLayout.contains(name)) {

                dispatcher.removeClass(name)
                gridLayout.removeObject(name)

                drawingCanvas.requestPaint()
                clearTextFields()
                drawingCanvas.selectedClass = ""
            }
        }
    }
}
