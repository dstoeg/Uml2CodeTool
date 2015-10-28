#ifndef UREFERENCE
#define UREFERENCE


#include "uAccess.h"

class uInheritable;

class uReference {

public:
    uReference(uInheritable * reference, uAccess access);
    uAccess getAccess() const;

private:
    uInheritable * mClass;
    uAccess mAccess;
};

#endif // UREFERENCE

