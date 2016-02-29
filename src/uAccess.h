#ifndef UACCESS
#define UACCESS

#include <string>

/**
 * @brief The uAccess enum specifies whether a class, method or function is public, private or protected.
 */


enum uAccess {
    uPublic,
    uPrivate,
    uProtected
};

/**
 * @brief This function is called from the code generation methods
 * @param access
 * @return a string specifying the access.
 */

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
/**
 * @brief getAccessUmlString
 * @param access
 * @return A string with a symbol related to the access:
 * "+" for public, "-" for private, "#" for protected and nothing in any other situation.
 */

static std::string getAccessUmlString(uAccess access) {
    switch (access) {
        case uPublic:
            return "+";
            break;
        case uPrivate:
            return "-";
            break;
        case uProtected:
            return "#";
            break;
        default:
            return "";
            break;
    }
}

/**
 * @brief This function is used to read from the graphic diagram and create the class, method or attribute in the logic.
 * @param c
 * @return the uAccess (public, private or protected) depending on the char (+, - or # respectively)
 */

static uAccess getAccessFromChar(char c) {
    switch (c) {
        case '+':
            return uPublic;
            break;
        case '-':
            return uPrivate;
            break;
        case '#':
            return uProtected;
            break;
        default:
            return uPublic;
            break;
    }
}

/**
 * @brief This function is used to read from the graphic diagram and create the class, method or attribute in the logic.
 * @param str
 * @return the uAccess (public, private or protected) depending on the string
 */

static uAccess getAccessFromString(std::string str) {
    if(str == "public")
        return uPublic;

    if(str == "private")
        return uPrivate;

    if(str == "protected")
        return uProtected;

    return uPublic;
}


#endif // UACCESS

