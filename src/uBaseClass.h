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
    virtual std::string getParent() const;

protected:

};

#endif // UBASECLASS_H
