#include "uClassButton.h"
#include "uClassFactory.h"
#include "uDebugPrinter.h"
#include "uClassDiagram.h"

uClassButton &uClassButton::getInstance()
{
    static uClassButton mInstance;
    return mInstance;
}

void uClassButton::update(const std::string &oldName, uAccess access, const std::string &newName, TParameters &attributes, TMethods &methods, TReferences &references, uInheritable *base)
{
    if (uClassDiagram::getInstance().find(QString::fromStdString(oldName)) != 0){
        uClassDiagram::getInstance().removeClass(QString::fromStdString(oldName));
        uClassDiagram::getInstance().addClass(uClassFactory::getInstance().createClass(uClassType::eBaseClass ,access, newName, attributes, methods, references, base));
    }else
        uDebugPrinter::printText("updating ERROR: Class "+ oldName + " not found");
}

void uClassButton::create(uAccess access, const std::string &name, TParameters &attributes, TMethods &methods, TReferences &references, uInheritable *base)
{
    uClassDiagram::getInstance().addClass(uClassFactory::getInstance().createClass(uClassType::eBaseClass ,access, name, attributes, methods, references, base));
}
