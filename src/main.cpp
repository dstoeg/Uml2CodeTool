#include <iostream>
#include <vector>

#include "uAccess.h"
#include "uParameter.h"
#include "uMethod.h"
#include "uBaseClass.h"
#include "uLanguageCpp.h"
#include "uLanguageJava.h"
#include "uCodeGenerationVisitor.h"

using namespace std;

int main()
{
    // create a random method
    vector<uParameter> params;
    params.push_back(uParameter(uPrivate , "int", "param1"));
    params.push_back(uParameter(uPrivate , "string", "param2"));
    params.push_back(uParameter(uPrivate , "float", "param3"));
    uMethod method( uPublic, "void", "foo", params);

    // create a random class
    uBaseClass baseClass("ChildClass");
    baseClass.setAccess(uPublic);
    baseClass.addMethod(method);
    baseClass.addAttribute(uParameter(uPrivate , "int", "param1"));
    baseClass.addAttribute(uParameter(uProtected , "string", "param2"));
    baseClass.addAttribute(uParameter(uPublic , "float", "param3"));

    // generate C++ header file
    cout << endl << "generating C++ files" << endl;
    uLanguageStrategy * strategy = new uLanguageCPP();
    uCodeGenerationVisitor * generator = new uCodeGenerationVisitor(strategy);
    generator->setFileAttributes("daniel stoeger", "21/9/15");
    baseClass.accept(generator);

    // generate Java class file
    cout << endl << "generating Java files" << endl;
    strategy = new uLanguageJava();
    generator->setLanguage(strategy);
    baseClass.accept(generator);

    return 0;
}

