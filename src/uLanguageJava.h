#ifndef ULANGUAGEJAVA_H
#define ULANGUAGEJAVA_H

#include "uLanguageStrategy.h"

class uLanguageJava : public uLanguageStrategy
{
public:
    uLanguageJava();
    virtual std::string createFileContent(uInheritable * aClass, std::string const& base = "");

protected:
    virtual std::string createAttribute(uParameter const& attribute);
    virtual std::string createMethod(uMethod const& method);
    virtual std::string createReference(uReference const& reference);


};

#endif // ULANGUAGEJAVA_H
