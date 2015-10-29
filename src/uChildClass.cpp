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

uInheritable *uChildClass::getBaseClass() const
{
    return mBaseClass;
}

void uChildClass::accept(uVisitor *visitor)
{
    visitor->visit(this);
}
