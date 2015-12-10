#include "uChildClass.h"
#include "uVisitor.h"
#include "uDebugPrinter.h"


uChildClass::uChildClass(std::string const& name) : uInheritable(name)
{
    mHasParent = true;
    mBaseClass = NULL;
}

uChildClass::uChildClass(std::string const& name, uInheritable * base) : uInheritable(name)
{
    mHasParent = true;
    mBaseClass = base;
}

uChildClass::uChildClass(uAccess access, const std::string &name, TParameters &attributes, TMethods &methods, TReferences &references, uInheritable *base) : uInheritable(access, name, attributes, methods, references)
{
    mHasParent = true;
    mBaseClass = base;
}

uChildClass::~uChildClass()
{
    uDebugPrinter::printText("UChildClass DTor called");
}

void uChildClass::accept(uVisitor *visitor)
{
    visitor->visit(this);
}
