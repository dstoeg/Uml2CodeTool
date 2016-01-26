#ifndef UINHERITABLE_H
#define UINHERITABLE_H

#include "uMethod.h"
#include "uParameter.h"
#include "uReference.h"

#include <QString>

#include <vector>

class uVisitor;

/**
 * @brief The uInheritable class is an abstract class that specifies the structure of every UML Class,
 * a simple class, an interface or a child class (inherites from another).
 */

class uInheritable
{
public:
    //Constructors
    explicit uInheritable();
    uInheritable(std::string const& name);
    uInheritable(uAccess access, std::string const& name, TParameters & attributes, TMethods & methods, TReferences & references);
    virtual ~uInheritable();

    //Getters and Setters
    std::vector<uMethod *> getMethods() const;
    std::vector<uParameter *> getAttributes() const;
    std::vector<uReference*> getReferences() const;
    uAccess getAccess() const;
    void setAccess(uAccess access);
    std::string getName() const;
    uInheritable * getParent() const;
    void addMethod(uMethod * method);
    void addAttribute(uParameter * attribute);
    void addReference(uReference * reference);

    bool hasParent() const;//to check whether it is a childClass or not

    virtual void accept(uVisitor * visitor); //Accepts the code generation visitor

    //Overload of some operators
    inline bool operator==(const uInheritable &class1) const;
    inline bool operator!=(const uInheritable &class1) const;    

    QString qGetName() const; //To get the name for the QML UI

protected:
    std::string mName;
    uInheritable * mBaseClass;
    std::vector<uMethod*> mMethods;
    std::vector<uParameter*> mAttributes;
    std::vector<uReference*> mReferences;
    uAccess mAccess;
    bool mHasParent;
};

//Redefinition of collections and iterators
typedef std::vector<uInheritable*> TClasses;
typedef std::vector<uInheritable*>::iterator TClassesIter;
typedef std::vector<uInheritable*>::const_iterator TClassesConstIter;

#endif // UINHERITABLE_H
