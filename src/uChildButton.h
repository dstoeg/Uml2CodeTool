#ifndef UCHILDBUTTON_H
#define UCHILDBUTTON_H

#include "uButton.h"

class uChildButton : public uButton
{
public:
    static uChildButton &getInstance();
    void update(const std::string &oldName, uAccess access, const std::string &newName, TParameters &attributes, TMethods &methods, TReferences &references, uInheritable* base);
    uInheritable* create(uAccess access, std::string const& name, TParameters & attributes, TMethods & methods, TReferences & references, uInheritable *base);

protected:
    uChildButton(){}
    uChildButton(uChildButton const&);
    void operator = (uChildButton const&);
};

#endif // UCHILDBUTTON_H
