#ifndef UREFERENCE
#define UREFERENCE


#include "uAccess.h"
#include <vector>
#include <iterator>


class uInheritable;

class uReference {

public:
    uReference(uInheritable * reference, uAccess access);
    uAccess getAccess() const;

private:
    uInheritable * mClass;
    uAccess mAccess;
};

typedef std::vector<uReference*> TReferences;
typedef std::vector<uReference*>::iterator TReferencesIter;


#endif // UREFERENCE

