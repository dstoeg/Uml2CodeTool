#ifndef UCHILDCLASS_H
#define UCHILDCLASS_H

#include "uInheritable.h"

class uChildClass : public uInheritable
{
public:
    uChildClass(std::string const& name);
    uChildClass(std::string const& name, uInheritable * base);
    uChildClass(uAccess access, std::string const& name, TParameters & attributes, TMethods & methods, TReferences & references, uInheritable * base);
    uInheritable * getBaseClass() const;
    virtual void accept(uVisitor * visitor);

private:
    uInheritable * mBaseClass;
};

#endif // UCHILDCLASS_H
