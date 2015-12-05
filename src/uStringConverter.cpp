#include "uStringConverter.h"
#include <sstream>

using namespace std;

uStringConverter::uStringConverter()
{

}

TMethods uStringConverter::parseMethods(const std::string &text)
{
    TMethods methods;

    vector<string> methodStrings = splitString(text);

    for (vector<string>::iterator iter = methodStrings.begin(); iter < methodStrings.end(); ++iter) {
        string method = (*iter);
        uAccess access;
        string name;
        TParameters parameters;
        string returnType;
        size_t i = 0;

        // parse access
        while (!isAccessChar(method[i]) && i<method.size()) {i++; }
        access = getAccessFromChar(method[i]);

        // parse name
        i++;
        while (method[i] != '(' && i <method.size()) {
            if (method[i] != ' ') name += method[i];
            i++;
        }

        // parse parameters
        i++;
        while (method[i] != ')' && i <method.size()) {

            string type;
            while (method[i] != ' ' && i <method.size()) {
                type += method[i];
                i++;
            }

            i++;
            string name;
            while (method[i] != ',' && method[i] != ')' && i <method.size()) {
                name += method[i];
                i++;
            }
            if (method[i] == ',') i++;

            while(method[i] == ' ') i++;
            parameters.push_back(uParameter(uPublic, type, name));
        }

        // parse return type
        i++;
        while (i<method.size()) {
            if (method[i] != ' ' && method[i] != ':') returnType += method[i];
            i++;
        }

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

std::vector<std::string> uStringConverter::splitString(std::string const& text) {
    vector<string> methodStrings;
    string rest = text;
    size_t pos =text.find('\n');
    while (pos != string::npos) {
        methodStrings.push_back(rest.substr(0, pos));
        rest = rest.substr(pos+1, rest.size()-1);
        pos = rest.find('\n');
    }
    methodStrings.push_back(rest);
    return methodStrings;
}

bool uStringConverter::isAccessChar(char c) const{
    return (c == '+' || c == '-' || c == '#');
}

std::string uStringConverter::createAttributeString(const TParameters &attributes)
{
    // TODO

    return "";
}

