
#include "uParameter.h"

using namespace std;

uParameter::uParameter(const string &name, const string &type, uAccess access)
{
    mName = name;
    mType = type;
    mAccess = access;
}

string uParameter::getName() const
{
    return mName;
}

string uParameter::getType() const
{
    return mType;
}

uAccess uParameter::getAccess() const
{
    return mAccess;
}

