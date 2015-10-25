#ifndef UINHERITABLE_H
#define UINHERITABLE_H

#include "uMethod.h"
#include "uParameter.h"
#include "uReference.h"

#include <vector>

class uInheritable
{
public:
    uInheritable();
    // void accept(Visitor * visitor);
    std::vector<uMethod> getMethods() const;
    std::vector<uParameter> getAttributes() const;
    std::vector<uReference*> getReferences() const;
    uAccess getAccess() const;

private:
    std::vector<uMethod> mMethods;
    std::vector<uParameter> mAttributes;
    std::vector<uReference*> mReferences;
    uAccess mAccess;
};

#endif // UINHERITABLE_H
