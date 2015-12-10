#ifndef UCLASSDIAGRAM_H
#define UCLASSDIAGRAM_H

#include "uInheritable.h"

class uClassDiagram
{
public:
    static uClassDiagram &getInstance();
    void addClass(uInheritable * uClass);
    void removeClass(uInheritable * uClass);
    bool removeClass(QString const &name);
    bool contains(uInheritable * uClass) const;
    bool contains (std::string const& name) const;
    uInheritable * find(QString const& name) const;
    void applyVisitor(uVisitor* visitor);
    uInheritable * get(int index) const;
    int size() const;
    int getIndex(QString const& name) const;

private:
    TClasses mClasses;

protected:
    uClassDiagram();
    uClassDiagram(uClassDiagram const&);
    void operator = (uClassDiagram const&);
};



#endif // UCLASSDIAGRAM_H
