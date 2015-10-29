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
    // method1
    vector<uParameter> params;
    params.push_back(uParameter("param1", "int", uPrivate));
    params.push_back(uParameter("param2", "string", uPrivate));
    params.push_back(uParameter("param3", "float", uPrivate));
    uMethod method("myMethod", "int", uPublic, params);



    uBaseClass baseClass("ChildClass");
    baseClass.setAccess(uPublic);

    baseClass.addMethod(method);
    baseClass.addAttribute(uParameter("param1", "int", uProtected));
    baseClass.addAttribute(uParameter("param2", "int", uPrivate));
    baseClass.addAttribute(uParameter("param3", "string", uPublic));


    cout << endl << "C++" << endl;
    //uLanguageStrategy * strategy = new uLanguageCPP();
    uLanguageStrategy * strategy = new uLanguageJava();
    uCodeGenerationVisitor * generator = new uCodeGenerationVisitor(strategy);
    generator->setFileAttributes("daniel stoeger", "21/9/15");
    baseClass.accept(generator);



    return 0;
}

