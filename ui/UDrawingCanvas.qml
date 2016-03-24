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
    property bool selectingParent: false
    property int selectedX: 0
    property int selectedY: 0
    property bool selecting: false //this is a flag for avoiding uClassPanel.updateMethod() to be call when a class is clicked

    property bool arrowSelected: false
    property int arrowSelectedIndex: -1
    property int selectedArrowX: 0
    property int selectedArrowY: 0

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

        //draw each class from the uClassDiagram and checking position with the
        drawClasses()
        drawSegments()
    }

    function drawClasses()
    {
        for(var i = 0; i < dispatcher.getDiagramSize(); i++) {
            var name = dispatcher.getClassName(i);
            var methods = dispatcher.getClassMethods(i, true); //true implies "access" specified with symbol (+,-,#)
            var attributes = dispatcher.getClassAttributes(i, true); //true implies "access" specified with symbol (+,-,#)
            var parent = dispatcher.getClassParent(i);
            var isInterface = dispatcher.getClassIsInterface(i)
            var isAbstract = dispatcher.getClassIsAbstract(i)
            var x = gridLayout.getClassX(name);
            var y = gridLayout.getClassY(name);
            drawClass(x, y, name, methods, attributes, parent, isInterface, isAbstract);
        }
    }

    function drawSegments()
    {
        gridLayout.deleteNonExistentArrows();
        for(var i = 0; i < gridLayout.getArrowsSize(); i++)
        {
            var size = gridLayout.getArrowSize(i);
            for(var j = 0; j < size; j++){

                var x = gridLayout.getSegmentX(i, j);
                var y = gridLayout.getSegmentY(i, j);
                var x_to = gridLayout.getSegmentX_to(i, j);
                var y_to = gridLayout.getSegmentY_to(i, j);
                drawSegment(x, y, x_to, y_to);
                if(j == size -1){ //last segment in the arrow
                    var arrowType = gridLayout.getArrowType(i);
                    var segmentLength = Number(gridLayout.getSegmentLength(i, j));
                    uDebugger.qPrintText("Last segment length: " + segmentLength)
                    uDebugger.qPrintText("From: ("+Number(x +(x_to-x)/segmentLength)+","+Number(y + (y_to -y)/segmentLength)+") to ("+x_to+","+y_to+")")
                    drawReferenceSymbol(Number(x_to - 18*(x_to-x)/segmentLength),Number(y_to - 18*(y_to -y)/segmentLength), x_to, y_to, arrowType);
                }
            }
        }

        gridLayout.setArrowsDeleted();
    }

    function drawReferenceSymbol(x, y, x_to, y_to, arrowType)
    {
        if(arrowType === 0)
            drawTriangle(x, y, x_to, y_to, true)

        if(arrowType === 1)
            drawDiamond(x, y, x_to, y_to, false)

    }

    function drawClass(coordX, coordY, name, methods, attributes, parent, isInterface, isAbstract)
    {
        uDebugger.qPrintText("Writing class in the position (" + coordX + "," + coordY + ")")
        var x = Number(coordX);
        var y = Number(coordY);

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
        if(isAbstract)
            context.font = "italic " + parseInt(letterFont) + "px sans-serif";
        else
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

        //draw red frame around if the class is selected
        if(name == selectedClass)
        {
            context.beginPath();
            context.rect(x-1, y-1, classWidth+2, classHeight+2);
            context.strokeStyle = "red"
            context.stroke()
            context.strokeStyle = "black"
        }

        // draw class name
        context.moveTo(x+textOffset, y+nameOffset);
        context.beginPath();
        if(isInterface)
            name = "<<"+name+">>";
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
            if(gridLayout.createInheritance(name, parent))
            {
                autoGenerateInheritanceArrow(name, parent)
            }
        }

        // draw references
        var i;
        var referenceCount = dispatcher.getClassReferenceCount(name);
        for (i=0; i<referenceCount; i++) {
            var referenceName = dispatcher.getClassReference(name, i);
            if (referenceName != "") {
                if(gridLayout.createAggregation(referenceName, name)){
                    autoGenerateAggregationArrow(referenceName, name);
                }
            }
        }

//        // draw dependecies
//        var dependenceCount = dispatcher.getClassDependenceCount(name);
//        for (i=0; i<dependenceCount; i++) {
//            var dependenceName = dispatcher.getClassDependence(name, i);
//            if (dependenceName != "") {
//                gridLayout.createDependence(dependenceName, name);
//            }
//        }
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

        var objI = gridLayout.getClassX(name)
        var objJ = gridLayout.getClassY(name)

        var parentI = gridLayout.getClassX(parent)
        var parentJ = gridLayout.getClassY(parent)

        uDebugger.qPrintText("obj i: " + objI + ", j: " + objJ)
        uDebugger.qPrintText("parent i: " + parentI + ", j: " + parentJ)

        drawInheritanceArrow(objI, objJ, parentI, parentJ)
    }

    function drawSegment(x, y, x_to, y_to)
    {
        context.strokeStyle = "black";
        context.moveTo(x, y)
        context.lineTo(x_to, y_to)
        context.stroke();
    }

    function drawSegmentWidthHeight(x, y, width, height)
    {
        context.strokeStyle = "black";
        context.moveTo(x, y)
        context.lineTo(x + width, y+ height)
        context.stroke();
    }

    function autoGenerateInheritanceArrow(name, parent)
    {
        var x = gridLayout.getClassX(name)
        var y = gridLayout.getClassY(name)

        var x_to = gridLayout.getClassX(parent)
        var y_to = gridLayout.getClassY(parent)

        var index = gridLayout.getInheritanceIndex(name, parent)

        var paddingX = Number(offsetX()) - Number(getClassWidth())
        var paddingY = Number(offsetY()) - Number(getClassHeight())

        //Line1 up from child class
        gridLayout.addSegmentToArrow(index, x+getClassWidth()/2, y, 0, -paddingY/4)

        //Line2 right/left
        var newX;
        if(x_to<x)
        {
            gridLayout.addSegmentToArrow(index, x + getClassWidth()/2, y - paddingY/4, - Number(paddingX)/3 - getClassWidth()/2, 0)
            newX = Number(x - Number(paddingX)/3)
        }
        else{
            gridLayout.addSegmentToArrow(index, x+getClassWidth()/2, y - paddingY/4, paddingX/3 + getClassWidth()/2 ,0)
            newX = Number(x + Number(getClassWidth()) + paddingX/3)
        }

        //Line3 up/down
        gridLayout.addSegmentToArrow(index, newX ,y - paddingY/4, 0, y_to - y + getClassHeight() + paddingY/2)

        //Line4 left/rght
        gridLayout.addSegmentToArrow(index, newX ,y_to + getClassHeight() + paddingY/4, x_to + getClassWidth()/2 -newX ,0)

        //Line5 up Parent
        gridLayout.addSegmentToArrow(index, x_to + getClassWidth()/2 ,y_to + getClassHeight() + paddingY/4, 0 ,-paddingY/4)

//        var triangleW = getClassWidth()/10
//        var triangleH = paddingY/5
//        drawTriangle(x_to + getClassWidth()/2,y_to + getClassHeight(), triangleW ,triangleH ,true);
    }

    function drawInheritanceArrow(x, y, x_to, y_to) {

        var paddingX = Number(offsetX()) - Number(getClassWidth())
        var paddingY = Number(offsetY()) - Number(getClassHeight())

        context.strokeStyle = "black";
        //Line1 up from child class
        drawSegment(x+getClassWidth()/2, y, x+getClassWidth()/2, y - paddingY/4)
        //Line2 right/left
        var newX;
        if(x_to<x)
        {
            drawSegment(x+getClassWidth()/2, y - paddingY/4, x - Number(paddingX)/3 ,y - paddingY/4)
            newX = Number(x- Number(paddingX)/3)
        }
        else{
            drawSegment(x+getClassWidth()/2, y - paddingY/4, x + Number(getClassWidth()) + paddingX/3 ,y - paddingY/4)
            newX = Number(x + Number(getClassWidth()) + paddingX/3)
        }

        //Line3 up/down
        drawSegment(newX ,y - paddingY/4, newX, y_to + getClassHeight() + paddingY/4)

        //Line4 left/rght
        drawSegment(newX ,y_to + getClassHeight() + paddingY/4, x_to + getClassWidth()/2 ,y_to + getClassHeight() + paddingY/4)

        //Line5 up Parent
        drawSegment(x_to + getClassWidth()/2 ,y_to + getClassHeight() + paddingY/4, x_to + getClassWidth()/2 ,y_to + getClassHeight())

        var triangleW = getClassWidth()/10
        var triangleH = paddingY/5
        drawTriangle(x_to + getClassWidth()/2,y_to + getClassHeight(), triangleW ,triangleH ,true);
    }

    function drawAggregation(name, reference) {

        uDebugger.qPrintText("reference from " + name + " to " + reference)

        var objX = gridLayout.getClassX(name)
        var objY = gridLayout.getClassY(name)
        var referenceX = gridLayout.getClassX(reference)
        var referenceY = gridLayout.getClassY(reference)

        drawAggregationArrow(objX, objY, referenceX, referenceY)
    }

    function autoGenerateAggregationArrow(name, reference) {

        var x = gridLayout.getClassX(name)
        var y = gridLayout.getClassY(name)
        var x_to = gridLayout.getClassX(reference)
        var y_to = gridLayout.getClassY(reference)
        var index = gridLayout.getAggregationIndex(name, reference)

        var paddingX = Number(offsetX()) - Number(getClassWidth())
        var paddingY = Number(offsetY()) - Number(getClassHeight())

        context.strokeStyle = "black";
        //Line1 right/left from child class
        var newX;
        if(x_to<x){
            newX = x
            gridLayout.addSegmentToArrow(index, newX, y + getClassHeight()/2, -paddingX/2, 0)
            newX = x - paddingX/2
        }
        else{
            newX = x + getClassWidth()
            gridLayout.addSegmentToArrow(index, newX, y + getClassHeight()/2, paddingX/2, 0)
            newX = newX + paddingX/2
        }

        //Line2 up/down
        var newY
        if(y_to<y){
            gridLayout.addSegmentToArrow(index, newX, y + getClassHeight()/2, 0, y_to - y + getClassHeight()/2 + paddingY/3)
            newY = y_to + getClassHeight() + paddingY/3
        }
        else{
            gridLayout.addSegmentToArrow(index, newX, y + getClassHeight()/2, 0, y_to - y - getClassHeight()/2 - paddingY/3)
            newY = y_to - paddingY/3
        }

        //Line3 left/right
        //context.moveTo(newX, newY)
        if(x_to<x){
            //context.lineTo(x_to + getClassWidth() + paddingX/2, newY)
            gridLayout.addSegmentToArrow(index, newX, newY, x_to + getClassWidth() + paddingX/2 - newX, 0)
            newX = x_to + getClassWidth() + paddingX/2
        }
        else{
            gridLayout.addSegmentToArrow(index, newX, newY, x_to - paddingX/2 - newX ,0)
            //context.lineTo(x_to - paddingX/2, newY)
            newX = x_to - paddingX/2
        }

        //Line4 up/down
//        context.moveTo(newX ,newY)
//        context.lineTo(newX, y_to + getClassHeight()/2)
        gridLayout.addSegmentToArrow(index, newX, newY, 0, y_to + getClassHeight()/2 - newY)
        newY = y_to + getClassHeight()/2

        //Line5 up Parent
//        context.moveTo(newX ,newY)
        if(x_to<x){
//            context.lineTo(x_to + getClassWidth(), newY)
            gridLayout.addSegmentToArrow(index, newX, newY, x_to + getClassWidth() - newX, 0)
            newX = x_to + getClassWidth()
        }
        else{
            gridLayout.addSegmentToArrow(index, newX, newY, x_to - newX, 0)
            newX = x_to
        }

//        var diamondW = paddingX/2
//        var diamondH = paddingY/7
//        if(x_to<x)
//            drawDiamond(newX,newY, diamondW ,diamondH ,false);
//        else
//            drawDiamond(newX-diamondW,newY, diamondW ,diamondH ,false);
//        context.stroke();
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

    function drawTriangle( x, y, x_to, y_to, isFilled){


        var xLeft = x + (x_to - x)/2 - (y - y_to)/3;
        var yLeft = y + (y_to - y)/2 - (x_to - x)/3;
        var xRight = x + (x_to - x)/2 + (y - y_to)/3;
        var yRight = y + (y_to - y)/2 + (x_to - x)/3;

        context.strokeStyle = "black";

        // draw the triangle
        context.moveTo(xLeft,yLeft);
        context.lineTo(x_to, y_to);
        context.lineTo(xRight, yRight);
        context.closePath();
        if (isFilled)
            context.fill();
        context.stroke()
    }

    function drawDiamond( x, y, x_to, y_to, isFilled){
        context.strokeStyle = "black";

        // draw the diamond
        //vector from (x,y) to (x_to,y_to) is (x_to - x, y_to - y)
        //ortogonal is (y - y_to, x_to - x)

        var xLeft = x + (x_to - x)/2 - (y - y_to)/4;
        var yLeft = y + (y_to - y)/2 - (x_to - x)/4;
        var xRight = x + (x_to - x)/2 + (y - y_to)/4;
        var yRight = y + (y_to - y)/2 + (x_to - x)/4;
        context.stroke()

        //draw white line on segment line inside diamond
        context.beginPath()
        context.strokeStyle = "white"
        context.moveTo(x,y);
        context.lineTo(x_to,y_to);
        context.stroke();

        //draw actual diamond
        context.beginPath()
        context.strokeStyle = "black"
        context.moveTo(x,y);
        context.lineTo(xLeft, yLeft);
        context.moveTo(xLeft, yLeft)
        context.lineTo(x_to, y_to);
        context.moveTo(x_to, y_to)
        context.lineTo(xRight, yRight)
        context.moveTo(xRight, yRight)
        context.lineTo(x,y)      
        if (isFilled)
            context.fill();
        context.stroke()
    }


    function selectClass(x, y){

        uDebugger.qPrintText("Selected area in (" + x +"," + y + ")");

        uClassPanel.setFieldsBlack()

        //First check class
        var name = gridLayout.getString(parseInt(x), parseInt(y))

        if(name!=selectedClass)
            requestPaint()

        if (name != "" && !selectingParent) {

            selectedClass = name

            uDebugger.qPrintText("Selected class: " + name)

            selecting = true; //avoid uClassPanel.updateMethod() to be called

            //Get information from the logic background via UiDispatcher
            var idx = dispatcher.getClassIndex(name);
            var methods = dispatcher.getClassMethods(idx, false); //False implies "access" specified with letters (public, private...)
            var attributes = dispatcher.getClassAttributes(idx, false); //False implies "access" specified with letters
            var parent = dispatcher.getClassParent(idx)
            var isAbstract = dispatcher.getClassIsAbstract(idx)
            var isInterface = dispatcher.getClassIsInterface(idx)

            //set information in the text fields
            uClassPanel.setInformation(name, parent, methods, attributes, isAbstract, isInterface)

            selecting = false;//allows uClassPanel.updateMethod() to be called

        }
        else if(selectingParent && name != ""){
           uClassPanel.setParentField(name);
        }
        else
        {
            uClassPanel.clearTextFields()
            selectedClass = ""

            //if no class selected, check arrows
            arrowSelectedIndex = gridLayout.getArrowSelected(x,y)
            if(arrowSelectedIndex >= 0){
                uDebugger.qPrintText("Found arrow: " +arrowSelectedIndex)
                arrowSelected = true;
                selectedArrowX = x
                selectedArrowY = y
            }
        }


    }

    function moveClass(x, y)
    {
        var movX = x - selectedX
        var movY = y - selectedY
        if(selectedClass != "")
        {
            //uDebugger.qPrintText("Move class: " + selectedClass)
            gridLayout.moveObject(selectedClass, Number(movX), Number(movY))
            requestPaint()
        }
        else
        {
            //test for arrow movement
            if(arrowSelected){
                gridLayout.modifyArrow(arrowSelectedIndex, selectedArrowX, selectedArrowY, x, y)
                requestPaint()
                selectedArrowX = x
                selectedArrowY = y
            }
        }

        selectedX = x;
        selectedY = y;
    }

    function releasedMouse(x, y)
    {
        uDebugger.qPrintText("Mouse RELEASED in (" + x +"," + y + ")")
        if(arrowSelected){
//            gridLayout.mergeSegments(arrowSelectedIndex);
            requestPaint()
        }
        arrowSelected = false;
        arrowSelectedIndex = -1;

    }

    function getClassWidth()
    {
        return Number(width)/9
    }

    function getClassHeight()
    {
        return Number(height)/6;
    }

    //Class width + right padding
    function offsetX(){
        return Number(width)/(gridLayout.getWidth()/160)
    }

    //Class height + bottom padding
    function offsetY(){
        return Number(height)*(1.65)/(gridLayout.getHeight()/110)
    }
}
