#include "uLanguageJava.h"

using namespace std;

uLanguageJava::uLanguageJava()
{

}

std::string uLanguageJava::createMethod(const uMethod &method)
{
    string methodStr = "";
    vector<uParameter> params = method.getParameters();
    methodStr += getAccessString(method.getAccess()) + " " + method.getReturnType() + " " + method.getName() + "(";
    for (size_t i=0; i<params.size()-1; ++i) {
        methodStr += params[i].getType() + " " + params[i].getName() + ", ";
    }
    methodStr += params[params.size()-1].getType() + " " + params[params.size()-1].getName() + ");";

    return methodStr;
}

string uLanguageJava::createReference(const uReference &reference)
{
    // TODO
    return "";
}

string uLanguageJava::createAttribute(const uParameter &attribute)
{
    string attributeString = getAccessString(attribute.getAccess()) + " " + attribute.getType() + " " + attribute.getName() + ";";
    return attributeString;
}

string uLanguageJava::createFileContent(uInheritable * aClass, string const& base)
{
    return "";
}

