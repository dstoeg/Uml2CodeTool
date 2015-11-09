#include "uInterfaceButton.h"
#include "uDrawVisitor.h"
#include "uClassFactory.h"

uInterfaceButton &uInterfaceButton::getInstance()
{
    static uInterfaceButton mInstance;
    return mInstance;
}

void uInterfaceButton::update(uInheritable* inheritable)
{
    //Need the boxes to implement this class

    //inheritable = uClassFactory.getInstance()->createClass(information from the boxes)
    uDrawVisitor::getInstance().repaint();
}

//Constructor should be changed when the boxes are implemented with the GUI
uInheritable* uInterfaceButton::create(uClassType type, uAccess access, const std::string &name, TParameters &attributes, TMethods &methods, TReferences &references)
{
    uInheritable * newClass = uClassFactory::getInstance().createClass(uClassType::eInterface,access, name, attributes, methods, references, NULL);

    //mainDiagram.add(newClass);
    return newClass;
}

void uInterfaceButton::initializeBoxes()
{
     //Here there should be initialized the boxes, so we don't have to ask for parameters in the Create() method
}
