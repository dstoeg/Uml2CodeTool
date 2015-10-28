#include <iostream>
#include <vector>

#include "uAccess.h"
#include "uParameter.h"
#include "uMethod.h"
#include "uChildClass.h"
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



    uChildClass childClass("ChildClass");

    childClass.addMethod(method);
    childClass.addAttribute(uParameter("param1", "int", uProtected));
    childClass.addAttribute(uParameter("param2", "int", uPrivate));
    childClass.addAttribute(uParameter("param3", "string", uPublic));


    cout << endl << "C++" << endl;
    uLanguageStrategy * strategy = new uLanguageCPP();
    uCodeGenerationVisitor * generator = new uCodeGenerationVisitor(strategy);
    generator->setFileAttributes("daniel stoeger", "21/9/15");
    childClass.accept(generator);

    return 0;
}

