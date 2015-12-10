#ifndef UINHERITABLE_H
#define UINHERITABLE_H

#include "uMethod.h"
#include "uParameter.h"
#include "uReference.h"

#include <QString>

#include <vector>

class uVisitor;

class uInheritable
{
public:
    explicit uInheritable();
    uInheritable(std::string const& name);
    uInheritable(uAccess access, std::string const& name, TParameters & attributes, TMethods & methods, TReferences & references);
    virtual ~uInheritable();

    virtual void accept(uVisitor * visitor);
    std::vector<uMethod *> getMethods() const;
    std::vector<uParameter *> getAttributes() const;
    std::vector<uReference*> getReferences() const;
    uAccess getAccess() const;
    void setAccess(uAccess access);
    std::string getName() const;

    bool hasParent();
    inline bool operator==(const uInheritable &class1) const;
    inline bool operator!=(const uInheritable &class1) const;

    void addMethod(uMethod * method);
    void addAttribute(uParameter * attribute);
    void addReference(uReference * reference);

    QString qGetName() const;

protected:
    std::string mName;
    std::vector<uMethod*> mMethods;
    std::vector<uParameter*> mAttributes;
    std::vector<uReference*> mReferences;
    uAccess mAccess;
    bool mHasParent;
};

typedef std::vector<uInheritable*> TClasses;
typedef std::vector<uInheritable*>::iterator TClassesIter;
typedef std::vector<uInheritable*>::const_iterator TClassesConstIter;

#endif // UINHERITABLE_H
