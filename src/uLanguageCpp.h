#ifndef ULANGUAGECPP_H
#define ULANGUAGECPP_H

#include "uLanguageStrategy.h"

class uLanguageCPP : public uLanguageStrategy
{
public:
    uLanguageCPP();
    virtual std::string createMethod(uMethod const& method);
    virtual std::string createAttribute(uParameter const& attribute);

private:
};

#endif // ULANGUAGECPP_H
