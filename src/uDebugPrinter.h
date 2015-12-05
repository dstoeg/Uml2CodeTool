#ifndef UDEBUGPRINTER_H
#define UDEBUGPRINTER_H

#include "uInheritable.h"
#include <string>

class uDebugPrinter
{
public:
    uDebugPrinter();

    void printMethod(uMethod const& method) const;

private:
    void debug_print(std::string const& text) const;
};

#endif // UDEBUGPRINTER_H
