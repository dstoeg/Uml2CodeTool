#include "uClassButton.h"
#include "uDrawVisitor.h"
#include "uClassFactory.h"
#include "uDebugPrinter.h"

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

uInheritable* uClassButton::create(uAccess access, const std::string &name, TParameters &attributes, TMethods &methods, TReferences &references, uInheritable *base)
{
    uDebugPrinter::printText("creating new uBaseClass");

    uInheritable * newClass = uClassFactory::getInstance().createClass(uClassType::eBaseClass ,access, name, attributes, methods, references, base);
    return newClass;
}
