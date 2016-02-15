
#include <sstream>

#include "uStringConverter.h"
#include "uLanguageCpp.h"
#include "uLanguageJava.h"
#include "uLanguagePython.h"
#include "uProjectFile.h"
#include "uProjectFileQT.h"

#include "uDebugPrinter.h"

using namespace std;

uAccess uStringConverter::dAccess = uPublic;

uStringConverter::uStringConverter()
{

}
/**
 * @brief uStringConverter::parseMethods: Takes a string from the Methods text field and parse it to a TMethods object
 * @param text
 * @return equivalent TMethods
 */

TMethods uStringConverter::parseMethods(const std::string &text)
{
    TMethods methods;
    if (text.size() == 0) return methods;

    //split the string
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
        // if no char is found, assign defualt
        if(i >= method.size()-1){
            i=0;
            access = dAccess;
            //check if is string access
            string strAccess;
            //avoid spaces at the beginning
            while(method[i] == ' ')
                i++;

            //read first word
            while(method[i] != ' '){
                strAccess+=method[i];
                i++;
                if(strAccess.size() > 5 && isAccessString(strAccess)){
                    access = getAccessFromString(strAccess);
                    break;
                }
                if(strAccess.size() >= 10)
                    break;
            }

        } else {
            i++;
        }

        // parse name
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
            parameters.push_back(new uParameter(uPublic, type, name));
        }

        // parse return type
        i++;
        while (i<method.size()) {
            if (method[i] != ' ' && method[i] != ':') returnType += method[i];
            i++;
        }

        methods.push_back(new uMethod(access, returnType, name, parameters));
    }
    return methods;
}

TParameters uStringConverter::parseAttributes(const std::string &text)
{
    TParameters attributes;
    if (text.size() == 0) return attributes;

    vector<string> attributeStrings = splitString(text);

    for (vector<string>::iterator iter = attributeStrings.begin(); iter < attributeStrings.end(); ++iter) {
        string attribute = (*iter);
        uAccess access;
        string type = "";
        string name = "";

        size_t i = 0;

        // parse access
        while (!isAccessChar(attribute[i]) && i<attribute.size()) {i++; }
        access = getAccessFromChar(attribute[i]);
        // if no char is found, assign defualt
        if(i >= attribute.size()-1){
            i=0;
            access = dAccess;
            //check if is string access
            string strAccess;
            //avoid spaces at the beginning
            while(attribute[i] == ' ')
                i++;

            //read first word
            while(attribute[i] != ' '){
                strAccess+=attribute[i];
                i++;
                if(strAccess.size() > 5 && isAccessString(strAccess)){
                    access = getAccessFromString(strAccess);
                    break;
                }
                if(strAccess.size() >= 10)
                    break;
            }

        } else {
            i++;
        }

        // parse name
        while (attribute[i] != ':' && i <attribute.size()) {
            if (attribute[i] != ' ') name += attribute[i];
            i++;
        }

        // parse type
        i++;
        while (attribute[i] != '\n' && i < attribute.size()) {
            if (attribute[i] != ' ') type += attribute[i];
            i++;
        }
        attributes.push_back(new uParameter(access, type, name));
    }


    return attributes;
}

uLanguageStrategy * uStringConverter::parseLanguage(const string &language)
{
    uLanguageStrategy * strategy;
    if (language == "C++")
        strategy = new uLanguageCPP();
    else if (language == "Java")
        strategy = new uLanguageJava();
    else if (language == "Python")
        strategy = new uLanguagePython();
    else
        strategy = NULL;

    return strategy;
}

std::string uStringConverter::createMethodString(const TMethods &methods)
{
    stringstream text;
    for (TMethodsConstIter iter = methods.begin(); iter < methods.end(); ++iter) {

        // access
        text << getAccessUmlString((*iter)->getAccess());

        // method name
        text << " " << (*iter)->getName() << "(";

        // parameters
        TParameters parameters = (*iter)->getParameters();
        for (TParametersIter it = parameters.begin(); it<parameters.end(); ++it) {
            if (it == parameters.end()-1) {
                text << (*it)->getType() << " " << (*it)->getName();
            }
            else {
                text << (*it)->getType() << " " << (*it)->getName() << ", ";
            }
        }

        // end parameters
        text << ") : ";

        // return type
        text << (*iter)->getReturnType();
        if (iter + 1 != methods.end())
            text << '\n';

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

bool uStringConverter::isAccessChar(char c){
    return (c == '+' || c == '-' || c == '#');
}

bool uStringConverter::isAccessString(std::string str){
    return (str == "public" || str == "private" || str == "protected");
}

std::string uStringConverter::createAttributeString(const TParameters &attributes)
{
    stringstream text;
    for (TParametersConstIter iter = attributes.begin(); iter < attributes.end(); ++iter) {

        // access
        text << getAccessUmlString((*iter)->getAccess());

        // attribute name
        text << " " << (*iter)->getName() << " : ";

        //  type
        text << (*iter)->getType();

        if (iter + 1 != attributes.end())
            text << '\n';
    }

    return text.str();
}

QString uStringConverter::qCreateMethodString(const TMethods &methods)
{
    return QString::fromStdString(createMethodString(methods));
}

QString uStringConverter::qCreateMethodStringFromClass(uInheritable * obj)
{
    return qCreateMethodString(obj->getMethods());
}

QString uStringConverter::qCreateAttributeString(const TParameters &attributes)
{
    return QString::fromStdString(createAttributeString(attributes));
}

QString uStringConverter::qCreateAttributeStringFromClass(uInheritable *obj)
{
    return qCreateAttributeString(obj->getAttributes());
}


uProjectFile *uStringConverter::parseDevEnv(const std::string &devenv)
{
    uProjectFile * file;
    if (devenv == "QtCreator") {
        file = new uProjectFileQT();
    }
    else {
        file = NULL;
    }

    return file;
}
