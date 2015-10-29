#include "uLanguageCpp.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

uLanguageCPP::uLanguageCPP()
{
    mFileExtension = ".h";
}


std::string uLanguageCPP::createMethod(const uMethod & method)
{
    string methodStr = "";
    vector<uParameter> params = method.getParameters();
    methodStr += method.getReturnType() + " " + method.getName() + "(";
    for (size_t i=0; i<params.size()-1; ++i) {
        methodStr += params[i].getType() + " " + params[i].getName() + ", ";
    }
    methodStr += params[params.size()-1].getType() + " " + params[params.size()-1].getName() + ");";

    return methodStr;
}

string uLanguageCPP::createAttribute(const uParameter &attribute)
{
    string attributeString = attribute.getType() + " " + attribute.getName() + ";";
    return attributeString;
}

string uLanguageCPP::createReference(const uReference &reference)
{
    // TODO
    return "";
}

string uLanguageCPP::createFileContent(uInheritable * aClass, std::string const& base)
{
    stringstream fileContent;


    // start with multiple inclusion protection
    string includeGuard = aClass->getName() + "_H";
    transform(includeGuard.begin(), includeGuard.end(), includeGuard.begin(), ::toupper);
    fileContent << "#ifndef " << includeGuard << endl;
    fileContent << "#define " << includeGuard << endl << endl;

    // add include files
    // TODO

    // class name - inheritance
    if (base == "")
        fileContent << "class " << aClass->getName() << " {" << endl << endl;
    else
        fileContent << "class " << aClass->getName() << " : public " << base << "{" << endl << endl;


    string publicSection = "";
    string protectedSection = "";
    string privateSection = "";

    vector<uMethod> methods = aClass->getMethods();
    for (size_t i=0; i<methods.size(); i++) {
        if (methods[i].getAccess() == uPublic) {
            publicSection += "\t" + createMethod(methods[i]) + "\n";
        }
        else if (methods[i].getAccess() == uPrivate) {
            privateSection += "\t" + createMethod(methods[i]) + "\n";
        }
        else if (methods[i].getAccess() == uProtected) {
            protectedSection += "\t" + createMethod(methods[i]) + "\n";
        }
    }

    vector<uParameter> attributes = aClass->getAttributes();
    for (size_t i=0; i<attributes.size(); i++) {
        if (attributes[i].getAccess() == uPublic) {
            publicSection += "\t" + createAttribute(attributes[i]) + "\n";
        }
        else if (attributes[i].getAccess() == uPrivate) {
            privateSection += "\t" + createAttribute(attributes[i]) + "\n";
        }
        else if (attributes[i].getAccess() == uProtected) {
            protectedSection += "\t" + createAttribute(attributes[i]) + "\n";
        }
    }

    vector<uReference*> references = aClass->getReferences();
    for (size_t i=0; i<references.size(); i++) {
        if (references[i]->getAccess() == uPublic) {
            publicSection += "\t" + createReference((*references[i])) + "\n";
        }
        else if (references[i]->getAccess() == uPrivate) {
            privateSection += "\t" + createReference((*references[i])) + "\n";
        }
        else if (references[i]->getAccess() == uProtected) {
            protectedSection += "\t" + createReference((*references[i])) + "\n";
        }
    }


    // public section
    fileContent << "public: " << endl;
    fileContent << publicSection << endl;

    // protected section
    fileContent << "protected: " << endl;
    fileContent << protectedSection << endl;

    // private section
    fileContent << "private: " << endl;
    fileContent << privateSection << endl;

    fileContent << "};" << endl << endl;

    fileContent << "#endif" << endl;

    return fileContent.str();
}

