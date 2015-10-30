#ifndef ULANGUAGE_PYTHON_H
#define ULANGUAGE_PYTHON_H

#include "uLanguageStrategy.h"

class uLanguagePython : public uLanguageStrategy
{
public:
    uLanguagePython();
    virtual std::string createFileContent(uInheritable * aClass, std::string const& base);

protected:
    virtual std::string createMethod(uMethod const& method);
    virtual std::string createAttribute(uParameter const& attribute);
    virtual std::string createReference(uReference const& reference);
};

#endif // ULANGUAGE_PYTHON_H
