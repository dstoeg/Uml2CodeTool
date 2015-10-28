#include "uBaseClass.h"
#include "uVisitor.h"

uBaseClass::uBaseClass(std::string const& name) : uInheritable(name)
{
    mHasParent = false;
}

void uBaseClass::accept(uVisitor *visitor)
{
    visitor->visit(this);
}


