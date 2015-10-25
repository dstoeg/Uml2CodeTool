#ifndef UCLASSFACTORY_H
#define UCLASSFACTORY_H

#include "uClassType.h"
#include "uBaseClass.h"
#include "uChildClass.h"
#include "uInterface.h"

class uClassFactory
{
public:
    uClassFactory();
    uInheritable * createClass(uClassType type);

private:

};

#endif // UCLASSFACTORY_H
