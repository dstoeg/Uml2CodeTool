#include "uChildButton.h"
#include "uClassFactory.h"
#include "uDebugPrinter.h"
#include "uClassDiagram.h"


uChildButton &uChildButton::getInstance()
{
    static uChildButton mInstance;
    return mInstance;
}

void uChildButton::update(const std::string &oldName, uAccess access, const std::string &newName, TParameters &attributes, TMethods &methods, TReferences &references, uInheritable *base)
{
    uDebugPrinter::printText("updating uChildClass");
    if (uClassDiagram::getInstance().find(QString::fromStdString(oldName)) != 0){
        uClassDiagram::getInstance().removeClass(QString::fromStdString(oldName));
        uClassDiagram::getInstance().addClass(uClassFactory::getInstance().createClass(uClassType::eChildClass ,access, newName, attributes, methods, references, base));
    }else
        uDebugPrinter::printText("updating ERROR: Class "+ oldName + " not found");
}

uInheritable *uChildButton::create(uAccess access, const std::string &name, TParameters &attributes, TMethods &methods, TReferences &references, uInheritable *base)
{
    uDebugPrinter::printText("creating new uChildclass");
    uInheritable * newClass = uClassFactory::getInstance().createClass(uClassType::eChildClass ,access, name, attributes, methods, references, base);
    uClassDiagram::getInstance().addClass(newClass);
    return newClass;
}
