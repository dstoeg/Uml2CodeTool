#include "uChildButton.h"
#include "uClassFactory.h"
#include "uDebugPrinter.h"


uChildButton &uChildButton::getInstance()
{
    static uChildButton mInstance;
    return mInstance;
}

void uChildButton::update(uInheritable *inheritable)
{

}

uInheritable *uChildButton::create(uAccess access, const std::string &name, TParameters &attributes, TMethods &methods, TReferences &references, uInheritable *base)
{
    uDebugPrinter::printText("creating new uChildclass");
    uInheritable * newClass = uClassFactory::getInstance().createClass(uClassType::eChildClass ,access, name, attributes, methods, references, base);
    return newClass;
}
