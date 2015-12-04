#include "uStringConverter.h"
#include <sstream>

using namespace std;

uStringConverter::uStringConverter()
{

}

TMethods uStringConverter::parseMethods(const std::string &text)
{
    TMethods methods;

    // TODO split text into string array for methods
    vector<string> methodStrings;
    std::string delimiter = "\n";


    for (vector<string>::iterator iter = methodStrings.begin(); iter < methodStrings.end(); ++iter) {

        uAccess access;
        string name;
        TParameters parameters;
        string returnType;

        // TODO

        // 2.1 parse access

        // 2.1 parse name

        // 2.2 parse parameters

        // 2.3 parse return type

        methods.push_back(uMethod(access, returnType, name, parameters));
    }
    return methods;
}

TParameters uStringConverter::parseAttributes(const std::string &text)
{
    TParameters attributes;

    // TODO

    return attributes;
}

std::string uStringConverter::createMethodString(const TMethods &methods)
{
    stringstream text;
    for (TMethodsConstIter iter = methods.begin(); iter < methods.end(); ++iter) {

        // access
        text << getAccessUmlString(iter->getAccess()) << endl;

        // method name
        text << " " << iter->getName() << "(";

        // parameters
        TParameters parameters = iter->getParameters();
        for (TParametersIter it = parameters.begin(); it<parameters.end(); ++it) {
            if (it == parameters.end()-1) {
                text << it->getType() << " " << it->getName();
            }
            else {
                text << it->getType() << " " << it->getName() << ", ";
            }
        }

        // end parameters
        text << ") : ";

        // return type
        text << iter->getReturnType() << endl;
    }

    return text.str();
}

std::string uStringConverter::createAttributeString(const TParameters &attributes)
{
    // TODO

    return "";
}

