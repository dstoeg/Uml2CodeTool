#ifndef UCHILDCLASS_H
#define UCHILDCLASS_H

#include "uInheritable.h"

class uChildClass : public uInheritable
{
public:
    uChildClass();
    uChildClass(uInheritable * base);
    uInheritable * getBaseClass() const;

private:
    uInheritable * mBaseClass;
};

#endif // UCHILDCLASS_H
