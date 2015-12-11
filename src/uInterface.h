#ifndef UINTERFACE_H
#define UINTERFACE_H

#include "uInheritable.h"

class uInterface : public uInheritable
{
public:
    uInterface(std::string const& name);
    uInterface(uAccess access, std::string const& name, TParameters & attributes, TMethods & methods, TReferences & references);
    virtual void accept(uVisitor * visitor);

private:

};

#endif // UINTERFACE_H
