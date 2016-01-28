#ifndef UCHILDCLASS_H
#define UCHILDCLASS_H

#include "uInheritable.h"

/**
 * @brief The uChildClass class it is a uInheritable which represents classes that inherits from another
 */

class uChildClass : public uInheritable
{
public:
    uChildClass(std::string const& name);
    uChildClass(std::string const& name, uInheritable * base);
    uChildClass(uAccess access, std::string const& name, TParameters & attributes, TMethods & methods, TReferences & references, uInheritable * base);
    virtual ~uChildClass();
    virtual void accept(uVisitor * visitor);
};

#endif // UCHILDCLASS_H
