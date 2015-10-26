#include "uChildClass.h"


uChildClass::uChildClass(std::string const& name) : uInheritable(name)
{

}

uChildClass::uChildClass(std::string const& name, uInheritable * base) : uInheritable(name)
{
    mBaseClass = base;
}

uInheritable *uChildClass::getBaseClass() const
{
    return mBaseClass;
}
