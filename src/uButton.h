#ifndef UBUTTON_H
#define UBUTTON_H

#include "uInheritable.h"
#include "uClassType.h"
#include "uBaseClass.h"
#include "uChildClass.h"
#include "uInterface.h"

#include <vector>

/**
 * @brief The uButton class is the abstract class that defines the structure of every button (uChildButton, uClassButton and uInterfaceButton).
 * It is also a Singleton because we only need one.
 */

class uButton
{
public:
    static uButton &getInstance();
    virtual void update(const std::string &oldName, uAccess access, const std::string &newName, TParameters &attributes, TMethods &methods, TReferences &references, uInheritable* base) {}
    virtual void create(uAccess access, std::string const& name, TParameters & attributes, TMethods & methods, TReferences & references, uInheritable *base = NULL) {}

protected:
    uButton();
    uButton(uButton const&);
    void operator=(uButton const&);
};

#endif // UBUTTON_H
