//Array of classes that are going to be printed
var classes = []

function drawClasses(){
    console.log("Inside drawClasses, classesSize: "+classes.length)
    classes.forEach( function(newClass){
        console.log("Trying to draw: "+newClass.name)
        drawClass(newClass.x, newClass.y, newClass.name, newClass.methods, newClass.attributes);
    })
}

function insertClass(coordX, coordY, newName, newMethods, newAttributes){
    var classCreated = {
        x: coordX,
        y: coordY,
        name: newName,
        methods: newMethods,
        attributes: newAttributes
    }
    classes.push(classCreated);
    console.log("newClassCreated, classesSize: "+classes.length)
}

function drawClass(x, y, name, methods, attributes) {

    console.log("Drawing class: "+name)
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
