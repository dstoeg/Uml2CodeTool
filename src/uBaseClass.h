#ifndef UBASECLASS_H
#define UBASECLASS_H

#include "uInheritable.h"

class uBaseClass : public uInheritable
{
public:
    uBaseClass(std::string const& name);
    virtual void accept(uVisitor * visitor);

protected:

};

#endif // UBASECLASS_H
