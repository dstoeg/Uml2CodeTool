#include "uLanguageJava.h"

#include <sstream>

using namespace std;

uLanguageJava::uLanguageJava()
{
    mHasSeparateFiles = false;
    mImplementationFileExtension = "";
    mDeclarationFileExtension = ".java";
    mLineComment = "//";
    mName = "Java";
}

std::string uLanguageJava::createMethodDeclaration(uMethod * method)
{
    string methodStr = "";
    TParameters params = method->getParameters();
    methodStr += getAccessString(method->getAccess()) + " " + method->getReturnType() + " " + method->getName() + "(";
    for (TParametersIter iter = params.begin(); iter < params.end(); ++iter) {
        methodStr += (*iter)->getType() + " " + (*iter)->getName() + ", ";
    }
    methodStr += params[params.size()-1]->getType() + " " + params[params.size()-1]->getName() + ") \n\t{\n\t\t// TODO\n\t}\n\n";

    return methodStr;
}

string uLanguageJava::createReferenceDeclaration(const uReference &reference)
{
    // TODO
    return "";
}

string uLanguageJava::createMethodImplementation(const uMethod &method, std::string aClass)
{
    // not supported in java
    return "";
}

string uLanguageJava::createAttributeDeclaration(uParameter * attribute)
{
    string attributeString = getAccessString(attribute->getAccess()) + " " + attribute->getType() + " " + attribute->getName() + ";";
    return attributeString;
}

string uLanguageJava::createDeclarationFileContent(uInheritable * aClass, string const& base)
{
    stringstream fileContent;

    // add imports
    // TODO

    // class name + inheritance
    if (base != "")
        fileContent << getAccessString(aClass->getAccess()) << " class " << aClass->getName() << " implements " << base << "{" << endl << endl;
    else
        fileContent << getAccessString(aClass->getAccess()) << " class " << aClass->getName() << " {" << endl << endl;

    // attributes
    TParameters attributes = aClass->getAttributes();
    for (TParametersIter iter = attributes.begin(); iter < attributes.end(); ++iter) {
        fileContent << "\t" << createAttributeDeclaration(*iter) << endl << endl;
    }

    // methods
    TMethods methods = aClass->getMethods();
    for (TMethodsIter iter = methods.begin(); iter < methods.end(); ++iter) {
        fileContent << "\t" << createMethodDeclaration(*iter) << endl;
    }

    fileContent << "};" << endl;

    return fileContent.str();
}

string uLanguageJava::createImplementationFileContent(uInheritable *aClass, const string &base)
{
    // not supported in Java
    return "";
}
