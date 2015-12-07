#ifndef ULANGUAGEJAVA_H
#define ULANGUAGEJAVA_H

#include "uLanguageStrategy.h"

class uLanguageJava : public uLanguageStrategy
{
public:
    uLanguageJava();
    virtual std::string createDeclarationFileContent(uInheritable * aClass, std::string const& base = "");
    virtual std::string createImplementationFileContent(uInheritable * aClass, std::string const& base = "");

protected:
    virtual std::string createAttributeDeclaration(uParameter * attribute);
    virtual std::string createMethodDeclaration(uMethod *method);
    virtual std::string createReferenceDeclaration(uReference const& reference);
    virtual std::string createMethodImplementation(uMethod const& method, std::string aClass);
};

#endif // ULANGUAGEJAVA_H
