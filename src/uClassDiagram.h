#ifndef UCLASSDIAGRAM_H
#define UCLASSDIAGRAM_H

#include "uInheritable.h"

class uClassDiagram
{
public:
    uClassDiagram();
    void addClass(uInheritable * uClass);
    void removeClass(uInheritable * uClass);
    bool contains(uInheritable * uClass) const;
    uInheritable * find(std::string const& name) const;
    void applyVisitor(uVisitor* visitor);

private:
    TClasses mClasses;
};

#endif // UCLASSDIAGRAM_H
