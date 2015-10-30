#include "uLanguageCpp.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>


using namespace std;

uLanguageCPP::uLanguageCPP()
{
    mHasSeparateFiles = true;
    mDeclarationFileExtension = ".h";
    mImplementationFileExtension = ".cpp";
    mLineComment = "//";
}


std::string uLanguageCPP::createMethodDeclaration(const uMethod & method)
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

string uLanguageCPP::createAttributeDeclaration(const uParameter &attribute)
{
    string attributeString = attribute.getType() + " " + attribute.getName() + ";";
    return attributeString;
}

string uLanguageCPP::createReferenceDeclaration(const uReference &reference)
{
    // TODO
    return "";
}

string uLanguageCPP::createMethodImplementation(const uMethod &method, std::string aClass)
{
    string methodStr = "";
    vector<uParameter> params = method.getParameters();
    methodStr += method.getReturnType() + " " + aClass + "::" + method.getName() + "(";
    for (size_t i=0; i<params.size()-1; ++i) {
        methodStr += params[i].getType() + " " + params[i].getName() + ", ";
    }
    methodStr += params[params.size()-1].getType() + " " + params[params.size()-1].getName() + ") {\n\t//TODO\n}\n\n";

    return methodStr;
}


string uLanguageCPP::createDeclarationFileContent(uInheritable * aClass, std::string const& base)
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
            publicSection += "\t" + createMethodDeclaration(methods[i]) + "\n";
        }
        else if (methods[i].getAccess() == uPrivate) {
            privateSection += "\t" + createMethodDeclaration(methods[i]) + "\n";
        }
        else if (methods[i].getAccess() == uProtected) {
            protectedSection += "\t" + createMethodDeclaration(methods[i]) + "\n";
        }
    }

    vector<uParameter> attributes = aClass->getAttributes();
    for (size_t i=0; i<attributes.size(); i++) {
        if (attributes[i].getAccess() == uPublic) {
            publicSection += "\t" + createAttributeDeclaration(attributes[i]) + "\n";
        }
        else if (attributes[i].getAccess() == uPrivate) {
            privateSection += "\t" + createAttributeDeclaration(attributes[i]) + "\n";
        }
        else if (attributes[i].getAccess() == uProtected) {
            protectedSection += "\t" + createAttributeDeclaration(attributes[i]) + "\n";
        }
    }

    vector<uReference*> references = aClass->getReferences();
    for (size_t i=0; i<references.size(); i++) {
        if (references[i]->getAccess() == uPublic) {
            publicSection += "\t" + createReferenceDeclaration((*references[i])) + "\n";
        }
        else if (references[i]->getAccess() == uPrivate) {
            privateSection += "\t" + createReferenceDeclaration((*references[i])) + "\n";
        }
        else if (references[i]->getAccess() == uProtected) {
            protectedSection += "\t" + createReferenceDeclaration((*references[i])) + "\n";
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

string uLanguageCPP::createImplementationFileContent(uInheritable *aClass, const string &base)
{
    stringstream fileContent;

    // include header
    fileContent << endl << "#include \"" << aClass->getName() + mDeclarationFileExtension << "\"" << endl << endl;

    // add methods
    vector<uMethod> methods = aClass->getMethods();
    for (size_t i=0; i<methods.size(); i++) {
        fileContent << createMethodImplementation(methods[i], aClass->getName()) << endl;
    }

    return fileContent.str();
}
