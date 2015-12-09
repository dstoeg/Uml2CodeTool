#include "uInterfaceButton.h"
#include "uDrawVisitor.h"
#include "uClassFactory.h"
#include "uDebugPrinter.h"

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
uInheritable* uInterfaceButton::create(uAccess access, std::string const& name, TParameters & attributes, TMethods & methods, TReferences & references, uInheritable *base)
{
    uDebugPrinter::printText("creating new uInterface");
    uInheritable * newClass = uClassFactory::getInstance().createClass(uClassType::eInterface,access, name, attributes, methods, references, base);
    return newClass;
}

