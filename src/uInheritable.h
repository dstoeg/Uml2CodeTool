#ifndef UINHERITABLE_H
#define UINHERITABLE_H

#include "uMethod.h"
#include "uParameter.h"
#include "uReference.h"

#include <vector>

class uInheritable
{
public:
    uInheritable(std::string const& name);
    // void accept(Visitor * visitor);
    std::vector<uMethod> getMethods() const;
    std::vector<uParameter> getAttributes() const;
    std::vector<uReference*> getReferences() const;
    uAccess getAccess() const;
    std::string getName() const;

private:
    std::string mName;
    std::vector<uMethod> mMethods;
    std::vector<uParameter> mAttributes;
    std::vector<uReference*> mReferences;
    uAccess mAccess;
};

#endif // UINHERITABLE_H
