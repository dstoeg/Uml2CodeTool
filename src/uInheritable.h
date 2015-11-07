#ifndef UINHERITABLE_H
#define UINHERITABLE_H

#include "uMethod.h"
#include "uParameter.h"
#include "uReference.h"

#include <vector>

class uVisitor;

class uInheritable
{
public:
    uInheritable(std::string const& name);
    uInheritable(uAccess access, std::string const& name, TParameters & attributes, TMethods & methods, TReferences & references);
    virtual void accept(uVisitor * visitor);
    std::vector<uMethod> getMethods() const;
    std::vector<uParameter> getAttributes() const;
    std::vector<uReference*> getReferences() const;
    uAccess getAccess() const;
    void setAccess(uAccess access);
    std::string getName() const;
    bool hasParent() const;

    void addMethod(uMethod method);
    void addAttribute(uParameter attribute);
    void addReference(uReference * reference);

protected:
    std::string mName;
    std::vector<uMethod> mMethods;
    std::vector<uParameter> mAttributes;
    std::vector<uReference*> mReferences;
    uAccess mAccess;
    bool mHasParent;
};

typedef std::vector<uInheritable*> TClasses;

#endif // UINHERITABLE_H
