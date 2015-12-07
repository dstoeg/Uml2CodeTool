#ifndef ULANGUAGE_PYTHON_H
#define ULANGUAGE_PYTHON_H

#include "uLanguageStrategy.h"

class uLanguagePython : public uLanguageStrategy
{
public:
    uLanguagePython();
    virtual std::string createDeclarationFileContent(uInheritable * aClass, std::string const& base);

protected:
    virtual std::string createMethodDeclaration(uMethod *method);
    virtual std::string createAttributeDeclaration(uParameter *attribute);
    virtual std::string createReferenceDeclaration(uReference const& reference);
};

#endif // ULANGUAGE_PYTHON_H
