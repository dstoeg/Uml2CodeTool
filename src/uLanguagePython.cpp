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


std::string uLanguagePython::createMethodDeclaration(const uMethod & method)
{
    TParameters params;
    TParameters methodParams = method.getParameters();
    params.push_back(uParameter(uPublic, "", "self"));
    params.insert(params.end(), methodParams.begin(), methodParams.end());

    string methodStr = "def " + access(method.getAccess()) + method.getName() + "(";

    for (TParametersIter it = params.begin(); it != params.end(); it++) {
        methodStr += it->getName() + ", ";
    }

    return methodStr.substr(0, methodStr.length()-2) + "):\n        \"\"\"TODO: Method docstring\"\"\"\n        pass\n\n";

}

string uLanguagePython::createAttributeDeclaration(const uParameter &attribute)
{
    return "self." + attribute.getName() + " = None";
}

string uLanguagePython::createReferenceDeclaration(const uReference &reference)
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

    TParameters attributes = aClass->getAttributes();
    for (TParametersIter it = attributes.begin(); it != attributes.end(); it++) {
        content << "        " << createAttributeDeclaration(*it) << endl;
    }

    content << endl;

    TMethods methods = aClass->getMethods();
    for(TMethodsIter it = methods.begin(); it != methods.end(); it++) {
       content << "    " << createMethodDeclaration(*it) << endl; 
    }


    return content.str(); 
}
