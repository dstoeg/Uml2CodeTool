
#include "uReference.h"

using namespace std;

uReference::uReference(uInheritable * reference, uAccess access)
{
    mClass = reference;
    mAccess = access;
}

uAccess uReference::getAccess() const
{
    return mAccess;
}
