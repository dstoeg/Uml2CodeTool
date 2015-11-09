#ifndef UINTERFACEBUTTON_H
#define UINTERFACEBUTTON_H

#include "uButton.h"

class uInterfaceButton: public uButton
{
public:
    static uInterfaceButton &getInstance();
    void update(uInheritable* inheritable);
    uInheritable* create(uClassType type, uAccess access, std::string const& name, TParameters & attributes, TMethods & methods, TReferences & references);
    void initializeBoxes();

protected:
    uInterfaceButton(){}
    uInterfaceButton(uInterfaceButton const&);
    void operator=(uInterfaceButton const&);
};

#endif // UINTERFACEBUTTON_H
