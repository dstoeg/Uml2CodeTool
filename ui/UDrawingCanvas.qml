import QtQuick 2.3
import QtQuick.Window 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.LocalStorage 2.0

Canvas {
    Layout.fillHeight: true
    Layout.fillWidth: true
    Layout.margins: 5

    property string selectedClass: ""

    onPaint: {
        uClassPanel.setFieldsBlack()
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
        for(var i = 0; i < dispatcher.getDiagramSize(); i++) {
            var name = dispatcher.getClassName(i);
            var methods = dispatcher.getClassMethods(i);
            var attributes = dispatcher.getClassAttributes(i);
            var parent = dispatcher.getClassParent(i);
            var x = gridLayout.getI(name);
            var y = gridLayout.getJ(name);
            drawClass(x, y, name, methods, attributes, parent);
        }
    }


    function drawClass(coordX, coordY, name, methods, attributes, parent, referenced) {

        var x = getXfromCoord(coordX)
        var y = getYfromCoord(coordY)

        //console.log("Drawing class: "+name +", "+ methods +", "+ attributes)
        var classWidth = getClassWidth()
        var classHeight = getClassHeight()

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

        // draw inheritance
        if(parent != "") {
            drawInheritance(name, parent)
        }

        // draw references
        var referenceCount = dispatcher.getClassReferenceCount(name);
        for (var i=0; i<referenceCount; i++) {
            var referenceName = dispatcher.getClassReference(name, i);
            if (referenceName != "") {
                drawAggregation(name, referenceName)
            }
        }
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

    function drawInheritance(name, parent) {

        var objI = gridLayout.getI(name)
        var objJ = gridLayout.getJ(name)

        var parentI = gridLayout.getI(parent)
        var parentJ = gridLayout.getJ(parent)

        uDebugger.qPrintText("obj i: " + objI + ", j: " + objJ)
        uDebugger.qPrintText("parent i: " + parentI + ", j: " + parentJ)

        var objX = getXfromCoord(objI);
        var objY = getYfromCoord(objJ)

        var parentX = getXfromCoord(parentI)
        var parentY = getYfromCoord(parentJ)


        drawInheritanceArrow(objX, objY, parentX, parentY)
    }

    function drawInheritanceArrow(x, y, x_to, y_to) {

        var paddingX = Number(offsetX()) - Number(getClassWidth())
        var paddingY = Number(offsetY()) - Number(getClassHeight())

        context.strokeStyle = "black";
        //Line1 up from child class
        context.moveTo(x+getClassWidth()/2, y)
        context.lineTo(x+getClassWidth()/2, y - paddingY/4)
        //Line2 right/left
        context.moveTo(x+getClassWidth()/2, y - paddingY/4)
        var newX;
        if(x_to<x)
        {
            context.lineTo(x - Number(paddingX)/3 ,y - paddingY/4)
            newX = Number(x- Number(paddingX)/3)
        }
        else{
            context.lineTo(x + Number(getClassWidth()) + paddingX/3 ,y - paddingY/4)
            newX = Number(x + Number(getClassWidth()) + paddingX/3)
        }

        //Line3 up/down
        context.moveTo(newX ,y - paddingY/4)
        context.lineTo(newX, y_to + getClassHeight() + paddingY/4)

        //Line4 left/rght
        context.moveTo(newX ,y_to + getClassHeight() + paddingY/4)
        context.lineTo(x_to + getClassWidth()/2 ,y_to + getClassHeight() + paddingY/4)

        //Line5 up Parent
        context.moveTo(x_to + getClassWidth()/2 ,y_to + getClassHeight() + paddingY/4)
        context.lineTo(x_to + getClassWidth()/2 ,y_to + getClassHeight())

        var triangleW = getClassWidth()/10
        var triangleH = paddingY/5
        drawTriangle(x_to + getClassWidth()/2,y_to + getClassHeight(), triangleW ,triangleH ,true);
        context.stroke();
    }

    function drawAggregation(name, reference) {

        uDebugger.qPrintText("reference from " + name + " to " + reference)

        var objI = gridLayout.getI(name)
        var objJ = gridLayout.getJ(name)
        var referenceI = gridLayout.getI(reference)
        var referenceJ = gridLayout.getJ(reference)

        var objX = getXfromCoord(objI)
        var objY = getYfromCoord(objJ)
        var referenceX = getXfromCoord(referenceI)
        var referenceY = getYfromCoord(referenceJ)

        drawAggregationArrow(objX, objY, referenceX, referenceY)
    }

    function drawAggregationArrow(x, y, x_to, y_to) {

        var paddingX = Number(offsetX()) - Number(getClassWidth())
        var paddingY = Number(offsetY()) - Number(getClassHeight())

        context.strokeStyle = "black";
        //Line1 right/left from child class
        var newX;
        if(x_to<x){
            newX = x
            context.moveTo(newX, y + getClassHeight()/2)
            context.lineTo(x - paddingX/2, y + getClassHeight()/2)
            newX = x - paddingX/2
        }
        else{
            newX = x + getClassWidth()
            context.moveTo(newX, y + getClassHeight()/2)
            context.lineTo(newX + paddingX/2, y + getClassHeight()/2)
            newX = newX + paddingX/2
        }

        //Line2 up/down
        context.moveTo(newX, y + getClassHeight()/2)
        var newY
        if(y_to<y){
            context.lineTo(newX, y_to + getClassHeight() + paddingY/3)
            newY = y_to + getClassHeight() + paddingY/3
        }
        else{
            context.lineTo(newX, y_to - paddingY/3)
            newY = y_to - paddingY/3
        }

        //Line3 left/right
        context.moveTo(newX, newY)
        if(x_to<x){
            context.lineTo(x_to + getClassWidth() + paddingX/2, newY)
            newX = x_to + getClassWidth() + paddingX/2
        }
        else{
            context.lineTo(x_to - paddingX/2, newY)
            newX = x_to - paddingX/2
        }

        //Line4 up/down
        context.moveTo(newX ,newY)
        context.lineTo(newX, y_to + getClassHeight()/2)
        newY = y_to + getClassHeight()/2

        //Line5 up Parent
        context.moveTo(newX ,newY)
        if(x_to<x){
            //context.lineTo(x_to + getClassWidth(), newY)
            newX = x_to + getClassWidth()
        }
        else{
            //context.lineTo(x_to, newY)
            newX = x_to
        }

        var diamondW = paddingX/2
        var diamondH = paddingY/7
        if(x_to<x)
            drawDiamond(newX,newY, diamondW ,diamondH ,false);
        else
            drawDiamond(newX-diamondW,newY, diamondW ,diamondH ,false);
        context.stroke();
    }

//    //TODO complete - May be needed in the future and DashLine is not implemented in QML Canvas
//    function dashLine(){
//        var dashLen = stipple_length;
//        var dX = end_x - start_x;
//        var dY = end_y - start_y;
//        var dashes = Math.floor(Math.sqrt(dX * dX + dY * dY) / dashLen);
//        if (dashes == 0)
//        {
//            dashes = 1;
//        }
//        var dash_to_length = dash_length/dashLen
//        var space_to_length = 1 - dash_to_length
//        var dashX = dX / dashes;
//        var dashY = dY / dashes;
//        var x1 = start_x;
//        var y1 = start_y;

//        ctx.moveTo(x1,y1);

//        var q = 0;
//        while (q++ < dashes) {
//            x1 += dashX*dash_to_length;
//            y1 += dashY*dash_to_length;
//            ctx.lineTo(x1, y1);
//            x1 += dashX*space_to_length;
//            y1 += dashY*space_to_length;
//            ctx.moveTo(x1, y1);

//        }
//    }

    function drawTriangle(x,y,triangleWidth, triangleHeight, isFilled){
        context.strokeStyle = "black";

        // draw the triangle
        context.moveTo(x,y);
        context.lineTo(x-triangleWidth/2, y+triangleHeight);
        context.lineTo(x+triangleWidth/2, y+triangleHeight);
        context.closePath();
        if (isFilled)
            context.fill();
    }

    function drawDiamond( x , y , diamondWidth, diamondHeight, isFilled){
        context.strokeStyle = "black";

        // draw the diamond
        context.moveTo(x,y);
        context.lineTo(x+diamondWidth/2, y+diamondHeight/2);
        context.moveTo(x+diamondWidth/2, y+diamondHeight/2)
        context.lineTo(x+diamondWidth, y);
        context.moveTo(x+diamondWidth, y)
        context.lineTo(x+diamondWidth/2, y-diamondHeight/2)
        context.moveTo(x+diamondWidth/2, y-diamondHeight/2)
        context.lineTo(x,y)
        if (isFilled)
            context.fill();
    }


    function selectClass(x, y){
        uDebugger.qPrintText("Selected area in (" + x +"," + y + ")");

        var i = getCoordFromX(x)
        var j = getCoordFromY(y)

        uClassPanel.setFieldsBlack()

        if (!gridLayout.isEmpty(parseInt(i), parseInt(j))) {

            var name = gridLayout.getString(parseInt(i), parseInt(j))
            selectedClass = name
            uDebugger.qPrintText("name: " + name)

            var idx = dispatcher.getClassIndex(name);
            var methods = dispatcher.getClassMethods(idx);
            var attributes = dispatcher.getClassAttributes(idx);

            // TODO add parent
            uClassPanel.setInformation(i,j,name, "", methods, attributes)

        }
        else {
            uClassPanel.clearTextFields()
            selectedClass = ""
        }
    }

    function getXfromCoord(coordX)
    {
        return (Number(coordX)%gridLayout.getWidth()) * offsetX()
    }

    function getYfromCoord(coordY)
    {
        return (Number(coordY)%gridLayout.getHeight()) * offsetY() + Number(height)/45
    }

    function getCoordFromX(x)
    {
        return parseInt((Number(x) / (Number(width)/gridLayout.getWidth())))
    }

    function getCoordFromY(y)
    {
        return parseInt((Number(y) / (Number(height)/gridLayout.getHeight())))
    }

    function getClassWidth()
    {
        return Number(width)/(9*gridLayout.getWidth()/8)
    }

    function getClassHeight()
    {
        return (1.5)*Number(height)/(2*gridLayout.getHeight())
    }

    //Class width + right padding
    function offsetX(){
        return Number(width)/(9*gridLayout.getWidth()/9)
    }

    //Class height + bottom padding
    function offsetY(){
        return Number(height)*(1.65)/(8*gridLayout.getHeight()/5)
    }
}
