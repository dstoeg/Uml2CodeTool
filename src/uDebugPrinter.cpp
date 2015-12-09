#include "uDebugPrinter.h"
#include <iostream>
#include <typeinfo>

using namespace std;

uDebugPrinter::uDebugPrinter(QObject * parent) : QObject(parent)
{

}

void uDebugPrinter::printText(const string &text)
{
    debug_print(text);
}

void uDebugPrinter::qPrintText(const QString &text)
{
    printText(text.toStdString());
}

void uDebugPrinter::printMethod(uMethod * method)
{

    string output = getAccessString(method->getAccess()) + " " + method->getReturnType() + " " + method->getName() + "(";
    for (size_t i=0; i< method->getParameters().size(); i++) {
        if (i== method->getParameters().size()-1)
            output += method->getParameters()[i]->getType() + " " + method->getParameters()[i]->getName();
        else
            output += method->getParameters()[i]->getType() + " " + method->getParameters()[i]->getName() + ", ";
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

void uDebugPrinter::printAttribute(uParameter * attribute)
{
    string output = getAccessString(attribute->getAccess()) + " " + attribute->getType() + " " + attribute->getName();
    debug_print(output);
}

void uDebugPrinter::printAttributes(const TParameters &params)
{
    for (TParametersConstIter iter = params.begin(); iter != params.end(); ++iter) {
        printAttribute(*iter);
    }
}

void uDebugPrinter::printClass(uInheritable * obj)
{
    debug_print("Object type: " + string(typeid(obj).name()));
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

