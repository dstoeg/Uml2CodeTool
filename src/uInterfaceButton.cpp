#include "uInterfaceButton.h"
#include "uClassFactory.h"
#include "uDebugPrinter.h"
#include "uClassDiagram.h"

uInterfaceButton &uInterfaceButton::getInstance()
{
    static uInterfaceButton mInstance;
    return mInstance;
}

void uInterfaceButton::update(const std::string &oldName, uAccess access, const std::string &newName, TParameters &attributes, TMethods &methods, TReferences &references, uInheritable *base)
{
    uDebugPrinter::printText("updating uInterface");
    if (uClassDiagram::getInstance().find(QString::fromStdString(oldName)) != 0){
        uClassDiagram::getInstance().removeClass(QString::fromStdString(oldName));
        uClassDiagram::getInstance().addClass(uClassFactory::getInstance().createClass(uClassType::eInterface ,access, newName, attributes, methods, references, base));
    }else
        uDebugPrinter::printText("updating ERROR: Class "+ oldName + " not found");
}


//Constructor should be changed when the boxes are implemented with the GUI
uInheritable* uInterfaceButton::create(uAccess access, std::string const& name, TParameters & attributes, TMethods & methods, TReferences & references, uInheritable *base)
{
    uDebugPrinter::printText("creating new uInterface");
    uInheritable * newClass = uClassFactory::getInstance().createClass(uClassType::eInterface,access, name, attributes, methods, references, base);
    return newClass;
}

