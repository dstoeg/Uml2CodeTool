import QtQuick 2.3
import QtQuick.Window 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.LocalStorage 2.0

Canvas {
    Layout.fillHeight: true
    Layout.fillWidth: true
    Layout.margins: 5

    onPaint: {
        // Get drawing context
        var context = getContext("2d");
        //context.fillStyle = "white"
        context.strokeStyle = "black"
        // Make canvas all white
        context.beginPath();
        context.clearRect(0, 0, width, height);
        context.fill();

        drawClasses()
    }

    function drawClasses(){
        var classDiagram = dispatcher.getClassDiagram();

        var diagramSize;
        if(classDiagram === null)
            diagramSize = 0
        else
            diagramSize = classDiagram.size()


        for(var i = 0; i < diagramSize; i++) {
            var name = classDiagram.get(i).qGetName();
            var methods = stringConverter.qCreateMethodStringFromClass(classDiagram.get(i));
            var attributes = stringConverter.qCreateAttributeStringFromClass(classDiagram.get(i));
            var x = gridLayout.getI(name);
            var y = gridLayout.getJ(name);

            drawClass(x, y, name, methods, attributes);
        }

    }

    function drawClass(coordX, coordY, name, methods, attributes) {

        var x = (Number(coordX)%gridLayout.getWidth()) * Number(width)/9
        var y = (Number(coordY)%gridLayout.getHeight()) * Number(height)*2/9

        //console.log("Drawing class: "+name +", "+ methods +", "+ attributes)
        var classWidth = Number(width)/10;
        var classHeight = Number(height)/5;

        var firstDelimiter1 = classHeight * 0.15;
        var firstDelimiter2 = classHeight * 0.16;
        var secondDelimiter = classHeight * 0.55;

        var textOffset = classWidth * 0.05;

        var nameOffset = classHeight * 0.10;
        var attributesOffset = classHeight * 0.26;
        var methodsOffset = classHeight * 0.65;

        var context = getContext("2d");
        context.strokeStyle = "black"
        var letterFont = width < height ? Number(width)/90: Number(height)/60;
        //console.log("LetterFont: " + letterFont)
        context.font = parseInt(letterFont) + "px sans-serif";

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
        wrapText(context, name, x+textOffset, y+nameOffset, classWidth, classHeight * 0.1)
        context.stroke();

        // draw attributes
        context.moveTo(x+textOffset, y+attributesOffset);
        context.beginPath();
        wrapText(context, attributes, x+textOffset, y+attributesOffset, classWidth, classHeight * 0.1)
        context.stroke();

        // draw methods
        context.moveTo(x+textOffset, y+methodsOffset);
        context.beginPath();
        wrapText(context, methods, x+textOffset, y+methodsOffset, classWidth, classHeight * 0.1)
        context.stroke();

    }

    function wrapText(context, text, x, y, maxWidth, lineHeight) {
        console.log(text)

        var finalText = text.split("\n");

        for (var ii = 0; ii < finalText.length; ii++) {

            var line = "";
            var words = finalText[ii].split(" ");

            for (var n = 0; n < words.length; n++) {
                var testLine = line + words[n] + " ";
                var metrics = context.measureText(testLine);
                var testWidth = metrics.width;

                if (testWidth > maxWidth) {
                    context.fillText(line, x, y);
                    line = words[n] + " ";
                    y += lineHeight;
                }
                else {
                    line = testLine;
                }
            }

            context.fillText(line, x, y);
            y += lineHeight;
        }
    }

    function drawInheritance(x, y, x_to, y_to) {

        var triangleX = Number(width)/65;
        var triangleY = Number(height)/50;
        // relies on classWidth, from drawClass function
        var classWidth = Number(width)/10;
        var offset = classWidth/2;
        var cx = x_to+offset; // x cord for center of destination class
        context.moveTo(x,y);
        context.strokeStyle = "black";
        // draw projection of arrow, then rotate
        context.lineTo(cx, y_to-triangleY);
        drawTriangle(cx,y_to,triangleX,triangleY,false);
        context.stroke();
    }

    function drawAggregation(x, y, x_to, y_to) {
        var triangleX = Number(width)/65;
        var triangleY = Number(height)/50;
        // relies on classWidth, from drawClass function
        var classWidth = Number(width)/10;
        var offset = classWidth/2;
        var cx = x_to+offset; // x cord for center of destination class
        context.moveTo(x,y);
        context.strokeStyle = "black";
        // draw projection of arrow, then rotate
        context.lineTo(cx, y_to-triangleY);
        drawTriangle(cx,y_to,triangleX,triangleY,true);
        context.stroke();
    }

    function drawTriangle(x,y,triangleWidth, triangleHeight, isFilled){
        context.strokeStyle = "black";

        // draw the rectangle
        context.moveTo(x-triangleWidth,y-triangleHeight);
        context.lineTo(x+triangleWidth, y-triangleHeight);
        context.lineTo(x,y);
        context.closePath();
        if (isFilled)
            context.fill();
    }



    function selectClass(x, y){
        //console.log("Selected area in (" + x +"," + y + ")")

    }

}
