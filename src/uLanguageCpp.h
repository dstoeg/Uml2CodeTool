#ifndef ULANGUAGECPP_H
#define ULANGUAGECPP_H

#include "uLanguageStrategy.h"

class uLanguageCPP : public uLanguageStrategy
{
public:
    uLanguageCPP();
    virtual std::string createDeclarationFileContent(uInheritable * aClass, std::string const& base);
    virtual std::string createImplementationFileContent(uInheritable * aClass, std::string const& base = "");

protected:
    virtual std::string createMethodDeclaration(uMethod *method);
    virtual std::string createAttributeDeclaration(uParameter *attribute);
    virtual std::string createReferenceDeclaration(uReference const& reference);
    virtual std::string createMethodImplementation(uMethod *method, std::string aClass);
};

#endif // ULANGUAGECPP_H
