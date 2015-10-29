#include "uMethod.h"


uMethod::uMethod(uAccess access, std::string const& returnType, std::string const& name, std::vector<uParameter> const& params)
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

