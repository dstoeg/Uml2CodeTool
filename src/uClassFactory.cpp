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

uInheritable * uClassFactory::createClass(uClassType type, uAccess access, const std::string &name, TParameters &attributes, TMethods &methods, TReferences &references, uInheritable *base)
{
    switch (type) {

        case eBaseClass:
            return new uBaseClass(access, name, attributes, methods, references);
            break;
        case eInterface:
            return new uInterface(access, name, attributes, methods, references);
            break;
        case eChildClass:
            return new uChildClass(access, name, attributes, methods, references, base);
            break;
        default:
            return NULL;
            break;
    }

}

