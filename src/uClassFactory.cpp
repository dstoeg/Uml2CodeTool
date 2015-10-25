#include "uClassFactory.h"

uClassFactory::uClassFactory()
{

}

uInheritable * uClassFactory::createClass(uClassType type)
{
    switch (type) {

        case eBaseClass:
            return new uBaseClass();
            break;
        case eInterface:
            return new uInterface();
            break;
        case eChildClass:
            return new uChildClass();
            break;
        default:
            return NULL;
            break;
    }
}

