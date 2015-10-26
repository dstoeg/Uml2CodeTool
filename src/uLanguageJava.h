#ifndef ULANGUAGEJAVA_H
#define ULANGUAGEJAVA_H

#include "uLanguageStrategy.h"

class uLanguageJava : public uLanguageStrategy
{
public:
    uLanguageJava();
    virtual std::string createMethod(uMethod const& method);

private:

};

#endif // ULANGUAGEJAVA_H
