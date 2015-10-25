#include "uChildClass.h"


uChildClass::uChildClass()
{

}

uChildClass::uChildClass(uInheritable * base)
{
    mBaseClass = base;
}

uInheritable *uChildClass::getBaseClass() const
{
    return mBaseClass;
}
