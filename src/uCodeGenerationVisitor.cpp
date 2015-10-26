#include "uCodeGenerationVisitor.h"

using namespace std;

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
    vector<uMethod> methods = childClass->getMethods();
    vector<uParameter> attributes = childClass->getAttributes();
    vector<uReference*> references = childClass->getReferences();
    uAccess access = childClass->getAccess();
    uInheritable * base = childClass->getBaseClass();
    string name = childClass->getName();


}

void uCodeGenerationVisitor::visit(uBaseClass *baseClass)
{
    vector<uMethod> methods = baseClass->getMethods();
    vector<uParameter> attributes = baseClass->getAttributes();
    vector<uReference*> references = baseClass->getReferences();
    uAccess access = baseClass->getAccess();
    string name = baseClass->getName();
}

void uCodeGenerationVisitor::visit(uInterface *interfaceClass)
{
    vector<uMethod> methods = interfaceClass->getMethods();
    vector<uParameter> attributes = interfaceClass->getAttributes();
    vector<uReference*> references = interfaceClass->getReferences();
    uAccess access = interfaceClass->getAccess();
    string name = interfaceClass->getName();
}

