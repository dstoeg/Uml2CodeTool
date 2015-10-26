#include "uInheritable.h"


uInheritable::uInheritable(const std::string &name)
{
    mName = name;
}

std::vector<uMethod> uInheritable::getMethods() const
{
    return mMethods;
}

std::vector<uParameter> uInheritable::getAttributes() const
{
    return mAttributes;
}

std::vector<uReference *> uInheritable::getReferences() const
{
    return mReferences;
}

uAccess uInheritable::getAccess() const
{
    return mAccess;
}

std::string uInheritable::getName() const
{
    return mName;
}

