#ifndef UCHILDBUTTON_H
#define UCHILDBUTTON_H

#include "uButton.h"

/**
 * @brief The uChildButton class manages the creation and updating of every child class
 */

class uChildButton : public uButton
{
public:
    static uChildButton &getInstance();
    void update(const std::string &oldName, uAccess access, const std::string &newName, TParameters &attributes, TMethods &methods, TReferences &references, uInheritable* base);
    void create(uAccess access, std::string const& name, TParameters & attributes, TMethods & methods, TReferences & references, uInheritable *base);

protected:
    uChildButton(){}
    uChildButton(uChildButton const&);
    void operator = (uChildButton const&);
};

#endif // UCHILDBUTTON_H
