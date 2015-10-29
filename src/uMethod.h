#ifndef UMETHOD_H
#define UMETHOD_H

#include "uParameter.h"
#include <vector>

class uMethod
{
public:
    uMethod(uAccess access, std::string const& returnType, std::string const& name, std::vector<uParameter> const& params);
    std::string getName() const;
    std::string getReturnType() const;
    uAccess getAccess() const;
    std::vector<uParameter> getParameters() const;

private:
    std::string mName;
    std::string mReturnType;
    uAccess mAccess;
    std::vector<uParameter> mParameters;
};

#endif // UMETHOD_H
