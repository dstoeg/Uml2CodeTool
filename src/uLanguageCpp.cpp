#include "uLanguageCpp.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "uDebugPrinter.h"

using namespace std;

uLanguageCPP::uLanguageCPP()
{
    mHasSeparateFiles = true;
    mDeclarationFileExtension = ".h";
    mImplementationFileExtension = ".cpp";
    mLineComment = "//";
    mName = "C++";
}


std::string uLanguageCPP::createMethodDeclaration(uMethod * method)
{
    string methodStr = "";
    TParameters params = method->getParameters();
    methodStr += method->getReturnType() + " " + method->getName() + "(";
    if (params.size() > 0) {
        for (TParametersIter iter = params.begin(); iter < params.end()-1; ++iter) {
            methodStr += (*iter)->getType() + " " + (*iter)->getName() + ", ";
        }
        methodStr += params[params.size()-1]->getType() + " " + params[params.size()-1]->getName();
    }
    methodStr += ");";

    return methodStr;
}

string uLanguageCPP::createAttributeDeclaration(uParameter * attribute)
{
    string attributeString = attribute->getType() + " " + attribute->getName() + ";";
    return attributeString;
}

string uLanguageCPP::createReferenceDeclaration(const uReference &reference)
{
    // TODO
    return "";
}

string uLanguageCPP::createMethodImplementation(uMethod * method, std::string aClass)
{
    string methodStr = "";
    TParameters params = method->getParameters();
    methodStr += method->getReturnType() + " " + aClass + "::" + method->getName() + "(";
    if (params.size() > 0) {
        for (TParametersIter iter = params.begin(); iter < params.end()-1; ++iter) {
            methodStr += (*iter)->getType() + " " + (*iter)->getName() + ", ";
        }
        methodStr += params[params.size()-1]->getType() + " " + params[params.size()-1]->getName();
    }
    methodStr += ") {\n\t//TODO\n}\n\n";

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

    TMethods methods = aClass->getMethods();
    for (TMethodsIter iter = methods.begin(); iter < methods.end(); ++iter) {
        if ((*iter)->getAccess() == uPublic) {
            publicSection += "\t" + createMethodDeclaration(*iter) + "\n";
        }
        else if ((*iter)->getAccess() == uPrivate) {
            privateSection += "\t" + createMethodDeclaration(*iter) + "\n";
        }
        else if ((*iter)->getAccess() == uProtected) {
            protectedSection += "\t" + createMethodDeclaration(*iter) + "\n";
        }
    }

    TParameters attributes = aClass->getAttributes();
    for (TParametersIter iter = attributes.begin(); iter < attributes.end(); ++iter) {
        if ((*iter)->getAccess() == uPublic) {
            publicSection += "\t" + createAttributeDeclaration(*iter) + "\n";
        }
        else if ((*iter)->getAccess() == uPrivate) {
            privateSection += "\t" + createAttributeDeclaration(*iter) + "\n";
        }
        else if ((*iter)->getAccess() == uProtected) {
            protectedSection += "\t" + createAttributeDeclaration(*iter) + "\n";
        }
    }

    TReferences references = aClass->getReferences();
    for (TReferencesIter iter = references.begin(); iter < references.end(); ++iter) {
        if ((*iter)->getAccess() == uPublic) {
            publicSection += "\t" + createReferenceDeclaration(*(*iter)) + "\n";
        }
        else if ((*iter)->getAccess() == uPrivate) {
            privateSection += "\t" + createReferenceDeclaration(*(*iter)) + "\n";
        }
        else if ((*iter)->getAccess() == uProtected) {
            protectedSection += "\t" + createReferenceDeclaration(*(*iter)) + "\n";
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
    TMethods methods = aClass->getMethods();
    for (TMethodsIter iter = methods.begin(); iter < methods.end(); ++iter) {
        fileContent << createMethodImplementation((*iter), aClass->getName()) << endl;
    }

    return fileContent.str();
}
