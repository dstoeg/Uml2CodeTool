#include "uClassButton.h"
#include "uDrawVisitor.h"
#include "uClassFactory.h"

uClassButton &uClassButton::getInstance()
{
    static uClassButton mInstance;
    return mInstance;
}

void uClassButton::update(uInheritable* inheritable)
{
    //Need the boxes to implement this class

    //inheritable = uClassFactory.getInstance()->createClass(information from the boxes)
    uDrawVisitor::getInstance().repaint();
}

uInheritable* uClassButton::create(uClassType type, uAccess access, const std::string &name, TParameters &attributes, TMethods &methods, TReferences &references, uInheritable *base)
{
    uInheritable * newClass = uClassFactory::getInstance().createClass(type,access, name, attributes, methods, references, base);

    //mainDiagram.add(newClass);
    return newClass;
}

void uClassButton::initializeBoxes()
{
     //Here there should be initialized the boxes, so we don't have to ask for parameters in the Create() method
}

