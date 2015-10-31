#include "uInterface.h"
#include "uVisitor.h"

uInterface::uInterface(std::string const& name) : uInheritable(name)
{
    mHasParent = false;
}

uInterface::uInterface(uAccess access, const std::string &name, TParameters &attributes, TMethods &methods, TReferences &references) : uInheritable(access, name, attributes, methods, references)
{

}

void uInterface::accept(uVisitor *visitor)
{
    visitor->visit(this);
}

