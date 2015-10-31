#include "uChildClass.h"
#include "uVisitor.h"


uChildClass::uChildClass(std::string const& name) : uInheritable(name)
{
    mHasParent = true;
    mBaseClass = NULL;
}

uChildClass::uChildClass(std::string const& name, uInheritable * base) : uInheritable(name)
{
    mBaseClass = base;
}

uChildClass::uChildClass(uAccess access, const std::string &name, TParameters &attributes, TMethods &methods, TReferences &references, uInheritable *base) : uInheritable(access, name, attributes, methods, references)
{
    mBaseClass = base;
}

uInheritable *uChildClass::getBaseClass() const
{
    return mBaseClass;
}

void uChildClass::accept(uVisitor *visitor)
{
    visitor->visit(this);
}
