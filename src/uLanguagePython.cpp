#include "uLanguagePython.h"

#include <sstream>

using namespace std;

std::string access(const uAccess access) {
  switch(access) {
    case uPrivate:
    case uProtected:
      return "_";
    default:
      return "";
  }
}

uLanguagePython::uLanguagePython()
{
   mDeclarationFileExtension = ".py"; 
   mHasSeparateFiles = false; 
   mLineComment = "#";
}


std::string uLanguagePython::createMethod(const uMethod & method)
{
    std::vector<uParameter> params;
    std::vector<uParameter> methodParams = method.getParameters();
    params.push_back(uParameter(uPublic, "", "self"));
    params.insert(params.end(), methodParams.begin(), methodParams.end());

    string methodStr = "def " + access(method.getAccess()) + method.getName() + "(";

    for (std::vector<uParameter>::const_iterator it = params.begin(); it != params.end(); it++) {
        methodStr += it->getName() + ", ";
    }

    return methodStr.substr(0, methodStr.length()-2) + "):\n        \"\"\"TODO: Method docstring\"\"\"\n        pass\n\n";

}

string uLanguagePython::createAttribute(const uParameter &attribute)
{
    return "self." + attribute.getName() + " = None";
}

string uLanguagePython::createReference(const uReference &reference)
{
    // TODO 
    return "";
}

string uLanguagePython::createDeclarationFileContent(uInheritable * aClass, std::string const& base)
{
    stringstream content;

    content << "class " << aClass->getName() << "(" << base << "):" << endl;


    content << "    " << "\"\"\"TODO: Class docstring\"\"\"" << endl << endl;

    content << "    def __init__(self):" << endl;
    content << "        \"\"\"TODO: Constructor docstring\"\"\"" << endl;

    std::vector<uParameter> attributes = aClass->getAttributes();
    for (std::vector<uParameter>::iterator it = attributes.begin(); it != attributes.end(); it++) {
        content << "        " << createAttribute(*it) << endl;
    }

    content << endl;

    std::vector<uMethod> methods = aClass->getMethods();
    for(std::vector<uMethod>::iterator it = methods.begin(); it != methods.end(); it++) {
       content << "    " << createMethod(*it) << endl; 
    }


    return content.str(); 
}
