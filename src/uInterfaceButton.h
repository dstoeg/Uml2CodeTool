#ifndef UINTERFACEBUTTON_H
#define UINTERFACEBUTTON_H

#include "uButton.h"
#include "uClassType.h"
#include "uBaseClass.h"
#include "uChildClass.h"
#include "uInterface.h"

class uInterfaceButton: public uButton
{
public:
    void update(uInheritable* inheritable);
    uInheritable* create(uClassType type, uAccess access, std::string const& name, TParameters & attributes, TMethods & methods, TReferences & references, uInheritable *base);
    void initializeBoxes();

protected:
    uInterfaceButton();
    uInterfaceButton(uInterfaceButton const&);
    void operator=(uInterfaceButton const&);
};

#endif // UINTERFACEBUTTON_H
