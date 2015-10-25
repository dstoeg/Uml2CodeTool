#include "uCodeGenerationVisitor.h"

uCodeGenerationVisitor::uCodeGenerationVisitor()
{

}

uCodeGenerationVisitor::uCodeGenerationVisitor(uLanguageStrategy *language)
{
    mLanguage = language;
}

void uCodeGenerationVisitor::setLanguage(uLanguageStrategy * language)
{
    mLanguage = language;
}

uLanguageStrategy * uCodeGenerationVisitor::getLanguage() const
{
    return mLanguage;
}

void uCodeGenerationVisitor::visit(uChildClass *childClass)
{
    std::vector<uMethod> methods = childClass->getMethods();
    std::vector<uParameter> attributes = childClass->getAttributes();
    std::vector<uReference*> references = childClass->getReferences();
    uAccess access = childClass->getAccess();
    uInheritable * base = childClass->getBaseClass();

}

void uCodeGenerationVisitor::visit(uBaseClass *baseClass)
{
    std::vector<uMethod> methods = baseClass->getMethods();
    std::vector<uParameter> attributes = baseClass->getAttributes();
    std::vector<uReference*> references = baseClass->getReferences();
    uAccess access = baseClass->getAccess();
}

void uCodeGenerationVisitor::visit(uInterface *interfaceClass)
{
    std::vector<uMethod> methods = interfaceClass->getMethods();
    std::vector<uParameter> attributes = interfaceClass->getAttributes();
    std::vector<uReference*> references = interfaceClass->getReferences();
    uAccess access = interfaceClass->getAccess();
}

