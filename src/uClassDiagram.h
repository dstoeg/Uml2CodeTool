#ifndef UCLASSDIAGRAM_H
#define UCLASSDIAGRAM_H

#include "uInheritable.h"

/**
 * @brief The uClassDiagram class is one of the main classes. It is a Singleton so there is only one and can be accesed from any other class.
 * This class stores all the uClasses in the diagram, and from it the UI takes the information (through the UIEventDispatcher) for printing them.
 * It contains all the methods for managing the collection of uClasses (add, remove, size, contains, find, getByIndex,...)
 * This class apply the code generator too (and any other visitor class that could be implemented in a future).
 */

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
    uInheritable * find(std::string const& name) const;
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
