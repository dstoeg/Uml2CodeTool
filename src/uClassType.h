#ifndef UCLASSTYPE
#define UCLASSTYPE

#include <string>

enum uClassType {
    eChildClass, //inherits from another class
    eInterface, //Interface
    eBaseClass  //does not inherit from any other class
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

