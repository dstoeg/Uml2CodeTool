#ifndef UCLASSTYPE
#define UCLASSTYPE

#include <string>

enum uClassType {
    eChildClass,
    eInterface,
    eBaseClass
};

static std::string getClassTypeString(uClassType type) {
    switch (type) {
        case eChildClass:
            return "ChildClass";
            break;
        case eInterface:
            return "Interface";
            break;
        case eBaseClass:
            return "BaseClass";
            break;
        default:
            return "";
            break;
    }
}

#endif // UCLASSTYPE

