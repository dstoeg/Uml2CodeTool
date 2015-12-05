import QtQuick 2.3
import QtQuick.Window 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1

Canvas {
    Layout.fillHeight: true
    Layout.fillWidth: true
    Layout.margins: 5

    onPaint: {
        // Get drawing context
        var context = getContext("2d");

        // Make canvas all white
        context.beginPath();
        context.clearRect(0, 0, width, height);
        context.fill();

        drawClass(300,300, "MyClass", "+ mParam1 : int", "+ getParam1() : int");

    }

    function drawClass(x, y, name, methods, attributes) {

        var classWidth = 300;
        var classHeight = 400;

        var firstDelimiter1 = classHeight * 0.15;
        var firstDelimiter2 = classHeight * 0.16;
        var secondDelimiter = classHeight * 0.55;

        var textOffset = classWidth * 0.05;

        var nameOffset = classHeight * 0.10;
        var attributesOffset = classHeight * 0.26;
        var methodsOffset = classHeight * 0.65;

        var context = getContext("2d");
        context.strokeStyle = "black"
        context.font = "20px sans-serif";

        // draw frame
        context.rect(x, y, classWidth, classHeight);

        // draw first delimiter
        context.moveTo(x, y+firstDelimiter1);
        context.lineTo(x+classWidth, y+firstDelimiter1);
        context.moveTo(x, y+firstDelimiter2);
        context.lineTo(x+classWidth, y+firstDelimiter2);

        // draw second delimiter
        context.moveTo(x, y+secondDelimiter);
        context.lineTo(x+classWidth, y+secondDelimiter);
        context.stroke();

        // draw class name
        context.moveTo(x+textOffset, y+nameOffset);
        context.beginPath();
        context.fillText(name, x+textOffset, y+nameOffset)
        context.stroke();

        // draw attributes
        context.moveTo(x+textOffset, y+attributesOffset);
        context.beginPath();
        context.fillText(attributes, x+textOffset, y+attributesOffset);
        context.stroke();

        // draw methods
        context.moveTo(x+textOffset, y+methodsOffset);
        context.beginPath();
        context.fillText(methods, x+textOffset, y+methodsOffset);
        context.stroke();

    }

    function drawInheritance(x, y, x_to, y_to) {

        context.moveTo(x, y);
        // draw projection of arrow, then rotate
    }

    function drawAggregation(x, y, x_to, y_to) {
        context.moveTo(x,y);
        // draw projection of arrow, then rotate
    }
}
