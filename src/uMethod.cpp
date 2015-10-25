#include "uMethod.h"


uMethod::uMethod(const std::string &name, const std::string &returnType, uAccess access, const std::vector<uParameter> &params)
{
    mName = name;
    mReturnType = returnType;
    mAccess = access;
    mParameters = params;
}

std::string uMethod::getName() const
{
    return mName;
}

std::string uMethod::getReturnType() const
{
    return mReturnType;
}

uAccess uMethod::getAccess() const
{
    return mAccess;
}

std::vector<uParameter> uMethod::getParameters() const
{
    return mParameters;
}

