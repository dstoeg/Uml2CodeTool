#include "uLanguageJava.h"

#include <sstream>

using namespace std;

uLanguageJava::uLanguageJava()
{
    mHasSeparateFiles = false;
    mImplementationFileExtension = "";
    mDeclarationFileExtension = ".java";
    mLineComment = "//";
}

std::string uLanguageJava::createMethodDeclaration(const uMethod &method)
{
    string methodStr = "";
    vector<uParameter> params = method.getParameters();
    methodStr += getAccessString(method.getAccess()) + " " + method.getReturnType() + " " + method.getName() + "(";
    for (size_t i=0; i<params.size()-1; ++i) {
        methodStr += params[i].getType() + " " + params[i].getName() + ", ";
    }
    methodStr += params[params.size()-1].getType() + " " + params[params.size()-1].getName() + ") \n\t{\n\t\t// TODO\n\t}\n\n";

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

string uLanguageJava::createAttributeDeclaration(const uParameter &attribute)
{
    string attributeString = getAccessString(attribute.getAccess()) + " " + attribute.getType() + " " + attribute.getName() + ";";
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
    vector<uParameter> attributes = aClass->getAttributes();
    for (size_t i=0; i<attributes.size(); i++) {
        fileContent << "\t" << createAttributeDeclaration(attributes[i]) << endl << endl;
    }

    // methods
    vector<uMethod> methods = aClass->getMethods();
    for (size_t i=0; i<methods.size(); i++) {
        fileContent << "\t" << createMethodDeclaration(methods[i]) << endl;
    }

    fileContent << "};" << endl;

    return fileContent.str();
}

string uLanguageJava::createImplementationFileContent(uInheritable *aClass, const string &base)
{
    // not supported in Java
    return "";
}
