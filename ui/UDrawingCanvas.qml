import QtQuick 2.3
import QtQuick.Window 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1

import "canvas.js" as CanvasJs

Canvas {
    Layout.fillHeight: true
    Layout.fillWidth: true
    Layout.margins: 5


    property

    onPaint: {
        // Get drawing context
        var context = getContext("2d");
        context.fillStyle = "white"

        // Make canvas all white
        context.beginPath();
        context.clearRect(0, 0, width, height);
        context.fill();

        console.log("trying to draw")
        CanvasJs.drawClasses();
        console.log("Sth drawing??")

    }


}
