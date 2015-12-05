#ifndef UDEBUGPRINTER_H
#define UDEBUGPRINTER_H

#include "uInheritable.h"
#include <string>

class uDebugPrinter
{
public:
    uDebugPrinter();
    static void printText(std::string const& text);
    static void printMethod(uMethod const& method);
    static void printMethods(TMethods const& methods);
    static void printAttribute(uParameter const& attribute);
    static void printAttributes(TParameters const& params);
    static void printClass(uInheritable const * const obj);

private:
    static void debug_print(std::string const& text);
};

#endif // UDEBUGPRINTER_H
