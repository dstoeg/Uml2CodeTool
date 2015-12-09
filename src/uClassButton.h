#ifndef UCLASSBUTTON_H
#define UCLASSBUTTON_H

#include "uButton.h"

class uClassButton : public uButton
{
public:
    static uClassButton &getInstance();
    void update(uInheritable* inheritable);
    uInheritable* create(uAccess access, std::string const& name, TParameters & attributes, TMethods & methods, TReferences & references, uInheritable *base = NULL);

protected:
    uClassButton(){}
    uClassButton(uClassButton const&);
    void operator = (uClassButton const&);
};

#endif // UCLASSBUTTON_H
