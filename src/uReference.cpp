
#include "uReference.h"

using namespace std;

uReference::uReference(uInheritable * reference, uAccess access)
{
    mClass = reference;
    mAccess = access;
    mReferenceSymbol = "";
}

uAccess uReference::getAccess() const
{
    return mAccess;
}


std::string uReference::getReferenceSymbol() const
{
    return mReferenceSymbol;
}
