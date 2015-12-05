#include "uDebugPrinter.h"
#include <iostream>

using namespace std;

uDebugPrinter::uDebugPrinter()
{

}

void uDebugPrinter::printMethod(const uMethod &method) const
{

    string output = getAccessString(method.getAccess()) + " " + method.getReturnType() + " " + method.getName() + "(";
    for (size_t i=0; i<method.getParameters().size(); i++) {
        if (i== method.getParameters().size()-1)
            output += method.getParameters()[i].getType() + " " + method.getParameters()[i].getName();
        else
            output += method.getParameters()[i].getType() + " " + method.getParameters()[i].getName() + ", ";
    }
    output += ")";
    debug_print(output);
}

void uDebugPrinter::debug_print(const string &text) const
{
    cout << "[DEBUG] " << text << endl;
}

