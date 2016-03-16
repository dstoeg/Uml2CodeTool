#ifndef UCLASSFACTORY_H
#define UCLASSFACTORY_H

#include "uClassType.h"
#include "uBaseClass.h"
#include "uChildClass.h"
#include "uInterface.h"

/**
 * @brief The uClassFactory class generates all the diferent uClasses. It has two creator functions, one with just the name (made for testind mainly) and
 * another with all the parameters. It is a singleton so it could be accessed from anywhere (the buttons use this class to create classes).
 */

class uClassFactory
{
public:
    static uClassFactory &getInstance();
    uInheritable * createClass(uClassType type, std::string const& name);
    uInheritable * createClass(uClassType type, uAccess access, std::string const& name, TParameters & attributes, TMethods & methods, TReferences & references, uInheritable *base, bool isAbstract);

private:
    uClassFactory();
    uClassFactory(uClassFactory const&);
    void operator=(uClassFactory const&);
};

#endif // UCLASSFACTORY_H
