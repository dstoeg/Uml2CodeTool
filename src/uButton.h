#ifndef UBUTTON_H
#define UBUTTON_H

#include "uInheritable.h"
#include "uClassType.h"
#include "uBaseClass.h"
#include "uChildClass.h"
#include "uInterface.h"

#include <vector>


class uButton
{
public:

    virtual void update(uInheritable* inheritable) {}
    virtual uInheritable* create(uClassType type, uAccess access, std::string const& name, TParameters & attributes, TMethods & methods, TReferences & references, uInheritable *base) {}
    static uButton* getInstance();
    virtual void initializeBoxes(){}

protected:
    uButton(){}
    uButton(uButton const&);
    void operator=(uButton const&);

private:
    uButton* mInstance = 0;
};

#endif // UBUTTON_H
