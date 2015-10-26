#include "uClassFactory.h"

uClassFactory::uClassFactory()
{

}

uInheritable * uClassFactory::createClass(uClassType type, std::string const& name)
{
    switch (type) {

        case eBaseClass:
            return new uBaseClass(name);
            break;
        case eInterface:
            return new uInterface(name);
            break;
        case eChildClass:
            return new uChildClass(name);
            break;
        default:
            return NULL;
            break;
    }
}

