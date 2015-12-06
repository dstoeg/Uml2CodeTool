#ifndef UINHERITABLE_H
#define UINHERITABLE_H

#include "uMethod.h"
#include "uParameter.h"
#include "uReference.h"

#include <QObject>
#include <QString>

#include <vector>

class uVisitor;

class uInheritable : public QObject
{
    Q_OBJECT
public:
    explicit uInheritable(QObject *parent = 0);
    uInheritable(std::string const& name);
    uInheritable(uAccess access, std::string const& name, TParameters & attributes, TMethods & methods, TReferences & references);
    virtual void accept(uVisitor * visitor);
    Q_INVOKABLE std::vector<uMethod> getMethods() const;
    Q_INVOKABLE std::vector<uParameter> getAttributes() const;
    std::vector<uReference*> getReferences() const;
    uAccess getAccess() const;
    void setAccess(uAccess access);
    std::string getName() const;

    bool hasParent();
    inline bool operator==(const uInheritable &class1) const;
    inline bool operator!=(const uInheritable &class1) const;

    void addMethod(uMethod method);
    void addAttribute(uParameter attribute);
    void addReference(uReference * reference);

    // QML function
    Q_INVOKABLE QString qGetName() const;

protected:
    std::string mName;
    std::vector<uMethod> mMethods;
    std::vector<uParameter> mAttributes;
    std::vector<uReference*> mReferences;
    uAccess mAccess;
    bool mHasParent;
};

typedef std::vector<uInheritable*> TClasses;
typedef std::vector<uInheritable*>::iterator TClassesIter;

#endif // UINHERITABLE_H
