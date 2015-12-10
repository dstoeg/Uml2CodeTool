#ifndef UINTERFACEBUTTON_H
#define UINTERFACEBUTTON_H

#include "uButton.h"

class uInterfaceButton: public uButton
{
public:
    static uInterfaceButton &getInstance();
    void update(const std::string &oldName, uAccess access, const std::string &newName, TParameters &attributes, TMethods &methods, TReferences &references, uInheritable* base);
    uInheritable* create(uAccess access, std::string const& name, TParameters & attributes, TMethods & methods, TReferences & references, uInheritable *base = NULL);

protected:
    uInterfaceButton(){}
    uInterfaceButton(uInterfaceButton const&);
    void operator=(uInterfaceButton const&);
};

#endif // UINTERFACEBUTTON_H
