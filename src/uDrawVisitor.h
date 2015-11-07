#ifndef UDRAWVISITOR_H
#define UDRAWVISITOR_H

#include "uVisitor.h"

class uDrawVisitor : public uVisitor
{
public:
    static uDrawVisitor &getInstance();
    void repaint(){} // this method repaints all the classes in the GUI. It is called from the Button each time that a new class is created or updated
    void visit(uChildClass * childClass) {}
    void visit(uBaseClass * baseClass) {}
    void visit(uInterface * interfaceClass) {}

protected:
    uDrawVisitor(){}
    uDrawVisitor(uDrawVisitor const&);
    void operator=(uDrawVisitor const&);
};

#endif // UDRAWVISITOR_H
