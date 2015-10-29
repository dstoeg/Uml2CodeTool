
#include "uParameter.h"

using namespace std;

uParameter::uParameter(uAccess access, std::string const&type, std::string const& name)
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

