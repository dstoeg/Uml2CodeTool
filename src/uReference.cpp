
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

uInheritable *uReference::getClass() const
{
    return mClass;
}

bool uReference::operator ==(const uReference &ref) const
{
    return mAccess==ref.getAccess() && mReferenceSymbol==ref.getReferenceSymbol() && mClass==ref.getClass();
}

bool uReference::operator !=(const uReference &ref) const
{
    return !operator==(ref);
}

static bool operator==(TReferences& ref1, TReferences& ref2){
    if(ref1.size()!=ref2.size())
        return false;

    TReferencesIter iter2 = ref2.begin();
    for (TReferencesIter iter1 = ref1.begin(); iter1 != ref1.end(); iter1++, iter2++ ){
        if((*iter1)!=(*iter2))
            return false;
    }
    return true;
}

static bool operator!=(TReferences& ref1, TReferences& ref2){
    return !operator==(ref1,ref2);
}
