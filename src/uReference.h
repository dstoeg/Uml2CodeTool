#ifndef UREFERENCE
#define UREFERENCE


#include "uAccess.h"
#include <vector>
#include <iterator>
#include <string>

class uInheritable;

class uReference
{
public:
    uReference(uInheritable * reference, uAccess access);
    uAccess getAccess() const;
    std::string getReferenceSymbol() const;
    uInheritable * getClass() const;
    inline bool operator ==(const uReference& ref) const;
    inline bool operator !=(const uReference& ref) const;

protected:
    std::string mReferenceSymbol;

private:
    uInheritable * mClass;
    uAccess mAccess;
};

typedef std::vector<uReference*> TReferences;
typedef std::vector<uReference*>::iterator TReferencesIter;


#endif // UREFERENCE

