#include "uBaseClass.h"
#include "uVisitor.h"

#include "uDebugPrinter.h"

uBaseClass::uBaseClass(std::string const& name) : uInheritable(name)
{
    mHasParent = false;
}

uBaseClass::uBaseClass(uAccess access, const std::string &name, TParameters &attributes, TMethods &methods, TReferences &references) : uInheritable(access, name, attributes, methods, references)
{
    mHasParent = false;
}

uBaseClass::~uBaseClass()
{
    uDebugPrinter::printText("uBaseClass DTor called: " + mName);
}

void uBaseClass::accept(uVisitor *visitor)
{
    visitor->visit(this);
}


