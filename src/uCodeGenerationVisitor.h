#ifndef UCODEGENERATIONVISITOR_H
#define UCODEGENERATIONVISITOR_H

#include "uVisitor.h"
#include "uLanguageStrategy.h"

class uCodeGenerationVisitor : public uVisitor
{
public:
    uCodeGenerationVisitor();
    uCodeGenerationVisitor(uLanguageStrategy * language);
    void setLanguage(uLanguageStrategy * language);
    uLanguageStrategy * getLanguage() const;

    virtual void visit(uChildClass * childClass);
    virtual void visit(uBaseClass * baseClass);
    virtual void visit(uInterface * interfaceClass);

private:
    uLanguageStrategy * mLanguage;
};

#endif // UCODEGENERATIONVISITOR_H
