#ifndef ULANGUAGECPP_H
#define ULANGUAGECPP_H

#include "uLanguageStrategy.h"

class uLanguageCPP : public uLanguageStrategy
{
public:
    uLanguageCPP();
    virtual std::string createFileContent(uInheritable * aClass, std::string const& base);

protected:
    virtual std::string createMethod(uMethod const& method);
    virtual std::string createAttribute(uParameter const& attribute);
    virtual std::string createReference(uReference const& reference);
};

#endif // ULANGUAGECPP_H
