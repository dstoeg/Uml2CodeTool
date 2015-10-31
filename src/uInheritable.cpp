#include "uInheritable.h"


uInheritable::uInheritable(const std::string &name)
{
    mName = name;
}

uInheritable::uInheritable(uAccess access, const std::string &name, TParameters &attributes, TMethods &methods, TReferences &references)
{
    mAccess = access;
    mName = name;
    mAttributes = attributes;
    mMethods = methods;
    mReferences = references;
}

void uInheritable::accept(uVisitor *visitor)
{

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

void uInheritable::setAccess(uAccess access)
{
    mAccess = access;
}

std::string uInheritable::getName() const
{
    return mName;
}

void uInheritable::addMethod(uMethod method)
{
    mMethods.push_back(method);
}

void uInheritable::addAttribute(uParameter attribute)
{
    mAttributes.push_back(attribute);
}

void uInheritable::addReference(uReference * reference)
{
    mReferences.push_back(reference);
}

