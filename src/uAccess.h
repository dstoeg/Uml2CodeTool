#ifndef UACCESS
#define UACCESS

#include <string>

enum uAccess {
    uPublic,
    uPrivate,
    uProtected
};

static std::string getAccessString(uAccess access) {
    switch (access) {
        case uPublic:
            return "public";
            break;
        case uPrivate:
            return "private";
            break;
        case uProtected:
            return "protected";
            break;
        default:
            return "";
            break;
    }
}

#endif // UACCESS

