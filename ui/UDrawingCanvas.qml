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

        var classDiagram = dispatcher.getClassDiagram();
        for(var i = 0; i < classDiagram.size(); i++) {
            var name = classDiagram.get(i).qGetName();
            //var methods = stringConverter.qCreateMethodString(classDiagram.get(i).getMethods());
            //var attributes = stringConverter.qCreateAttributeString(classDiagram.get(i).getAttributes());
            //drawClass(100, 100, name, methods, attributes);
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
                drawClass(2, 2, "name", "methods", "attributes")
            }
         )
    }

    function drawClass(coordX, coordY, name, methods, attributes) {

        var x = (Number(coordX)%8) * Number(width)/9
        var y = (Number(coordY)%5) * Number(height)*2/9

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
        context.font = "8px sans-serif";

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
