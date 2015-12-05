#include "uDebugPrinter.h"
#include <iostream>

using namespace std;

uDebugPrinter::uDebugPrinter()
{

}

void uDebugPrinter::printText(const string &text)
{
    debug_print(text);
}

void uDebugPrinter::printMethod(const uMethod &method)
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

void uDebugPrinter::printMethods(const TMethods &methods)
{
    for (TMethodsConstIter iter = methods.begin(); iter != methods.end(); ++iter) {
        printMethod(*iter);
    }
}

void uDebugPrinter::printAttribute(const uParameter &attribute)
{
    string output = getAccessString(attribute.getAccess()) + " " + attribute.getType() + " " + attribute.getName();
    debug_print(output);
}

void uDebugPrinter::printAttributes(const TParameters &params)
{
    for (TParametersConstIter iter = params.begin(); iter != params.end(); ++iter) {
        printAttribute(*iter);
    }
}

void uDebugPrinter::printClass(uInheritable const * const obj)
{
    debug_print("Name: " + obj->getName());
    debug_print("Methods: ");
    printMethods(obj->getMethods());
    debug_print("Attributes: ");
    printAttributes(obj->getAttributes());
}

void uDebugPrinter::debug_print(const string &text)
{
    cout << "[DEBUG] " << text << endl;
}

