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

        //drawClasses()

        var classDiagram = dispatcher.getClassDiagram();

        var diagramSize;
        if(classDiagram === null)
            diagramSize = 0
        else
            diagramSize = classDiagram.size()


        for(var i = 0; i < diagramSize; i++) {
            var name = classDiagram.get(i).qGetName();
            //var methods = stringConverter.qCreateMethodString(classDiagram.get(i).getMethods());
            //var attributes = stringConverter.qCreateAttributeString(classDiagram.get(i).getAttributes());
            var x = gridLayout.getI(name);
            var y = gridLayout.getJ(name);

            drawClass(x, y, name, "", "");
        }
    }

    function clearData(){
        var db = LocalStorage.openDatabaseSync("classesDB", "1.0", "Database for storing classes", 1000000);
        db.transaction(
            function(tx) {
                tx.executeSql('DROP TABLE IF EXISTS Classes');
            }
        )
    }

    function insertClass(coordX, coordY, newName, newMethods, newAttributes) {
        var db = LocalStorage.openDatabaseSync("classesDB", "1.0", "Database for storing classes", 1000000);

        db.transaction(
            function(tx) {
                // Create the database if it doesn't already exist
                tx.executeSql('CREATE TABLE IF NOT EXISTS Classes(coordx TEXT, coordy TEXT, name TEXT, methods TEXT, attributes TEXT)');

                // Add (another) class row
                tx.executeSql('INSERT INTO Classes VALUES(?, ?, ?, ?, ?)', [ coordX, coordY, newName, newMethods, newAttributes ]);
            }
        )
    }

    function drawClasses(){
        //Open the database
        var db = LocalStorage.openDatabaseSync("classesDB", "1.0", "Database for storing classes", 1000000);

        db.transaction(
            function(tx) {
                // Create the database if it doesn't already exist
                tx.executeSql('CREATE TABLE IF NOT EXISTS Classes(coordx TEXT, coordy TEXT, name TEXT, methods TEXT, attributes TEXT)');

                // Get all added classes
                var rs = tx.executeSql('SELECT * FROM Classes');

                //Draw each class
                for(var i = 0; i < rs.rows.length; i++) {
                    drawClass(rs.rows.item(i).coordx, rs.rows.item(i).coordy, rs.rows.item(i).name, rs.rows.item(i).methods, rs.rows.item(i).attributes)
                }
                //drawClass(2, 2, "name", "methods", "attributes")
            }
         )
    }

    function drawClass(coordX, coordY, name, methods, attributes, parent, referenced) {

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
        context.font = letterFont + "px sans-serif";

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

        // draw inheritance
        if(!parent === undefined)
        {
            drawInheritance(x+classWidth/2, y, 1,1)
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

        //Open the database
        var db = LocalStorage.openDatabaseSync("classesDB", "1.0", "Database for storing classes", 1000000);

        db.transaction(
            function(tx) {
                // Create the database if it doesn't already exist
                tx.executeSql('CREATE TABLE IF NOT EXISTS Classes(coordx TEXT, coordy TEXT, name TEXT, methods TEXT, attributes TEXT)');

                // Get all added classes
                var rs = tx.executeSql('SELECT * FROM Classes');

//                //look for the class
//                for(var i = 0; i < rs.rows.length; i++) {
//                    drawClass(rs.rows.item(i).coordx, rs.rows.item(i).coordy, rs.rows.item(i).name, rs.rows.item(i).methods, rs.rows.item(i).attributes)
//                }
//                drawClass(2, 2, "name", "methods", "attributes")
            }
         )
    }

}
