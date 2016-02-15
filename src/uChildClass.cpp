#include "uChildClass.h"
#include "uVisitor.h"
#include "uDebugPrinter.h"


uChildClass::uChildClass(std::string const& name) : uInheritable(name)
{
    mHasParent = true;
    mBaseClass = NULL;
    mIsInterface = false;
}

uChildClass::uChildClass(std::string const& name, uInheritable * base) : uInheritable(name)
{
    mHasParent = true;
    mBaseClass = base;
    mIsInterface = false;
}

uChildClass::uChildClass(uAccess access, const std::string &name, TParameters &attributes, TMethods &methods, TReferences &references, uInheritable *base, bool isAbstract) : uInheritable(access, name, attributes, methods, references, isAbstract)
{
    mHasParent = true;
    mBaseClass = base;
    mIsInterface = false;
}

uChildClass::~uChildClass()
{
    uDebugPrinter::printText("UChildClass DTor called");
}

void uChildClass::accept(uVisitor *visitor)
{
    visitor->visit(this);
}
