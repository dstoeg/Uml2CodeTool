#ifndef UBASECLASS_H
#define UBASECLASS_H

#include "uInheritable.h"

class uBaseClass : public uInheritable
{
public:
    uBaseClass(std::string const& name);
    uBaseClass(uAccess access, std::string const& name, TParameters & attributes, TMethods & methods, TReferences & references);
    virtual ~uBaseClass();
    virtual void accept(uVisitor * visitor);

protected:

};

#endif // UBASECLASS_H
