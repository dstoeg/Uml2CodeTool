#ifndef UINTERFACE_H
#define UINTERFACE_H

#include "uInheritable.h"

class uInterface : public uInheritable
{
public:
    uInterface(std::string const& name);
    virtual void accept(uVisitor * visitor);

private:

};

#endif // UINTERFACE_H
