#include "uInterface.h"
#include "uVisitor.h"

uInterface::uInterface(std::string const& name) : uInheritable(name)
{
    mHasParent = false;
}

void uInterface::accept(uVisitor *visitor)
{
    visitor->visit(this);
}

