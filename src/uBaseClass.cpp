#include "uBaseClass.h"
#include "uVisitor.h"

uBaseClass::uBaseClass(std::string const& name) : uInheritable(name)
{
    mHasParent = false;
}

uBaseClass::uBaseClass(uAccess access, const std::string &name, TParameters &attributes, TMethods &methods, TReferences &references) : uInheritable(access, name, attributes, methods, references)
{

}

void uBaseClass::accept(uVisitor *visitor)
{
    visitor->visit(this);
}


