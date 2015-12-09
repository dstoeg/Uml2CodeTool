#ifndef UCHILDBUTTON_H
#define UCHILDBUTTON_H

#include "uButton.h"

class uChildButton : public uButton
{
public:
    static uChildButton &getInstance();
    void update(uInheritable* inheritable);
    uInheritable* create(uAccess access, std::string const& name, TParameters & attributes, TMethods & methods, TReferences & references, uInheritable *base);

protected:
    uChildButton(){}
    uChildButton(uChildButton const&);
    void operator = (uChildButton const&);
};

#endif // UCHILDBUTTON_H
