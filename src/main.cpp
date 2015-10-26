#include <iostream>
#include <vector>

#include "uAccess.h"
#include "uParameter.h"
#include "uMethod.h"
#include "uLanguageCpp.h"
#include "uLanguageJava.h"
#include "uCodeGenerationVisitor.h"

using namespace std;

int main()
{
    // test the language strategy
    vector<uParameter> params;
    params.push_back(uParameter("param1", "int", uPrivate));
    params.push_back(uParameter("param2", "string", uPrivate));
    params.push_back(uParameter("param3", "float", uPrivate));
    uMethod method("myMethod", "int", uPublic, params);

    uLanguageStrategy * strategy = new uLanguageCPP();
    cout << endl << "C++" << endl;
    cout << strategy->createMethod(method) << endl;
    cout << strategy->createAttribute(params[0]) << endl;

    strategy = new uLanguageJava();
    cout << endl << "Java" << endl;
    cout << strategy->createMethod(method) << endl;
    cout << strategy->createAttribute(params[0]) << endl << endl;

    uCodeGenerationVisitor * generator = new uCodeGenerationVisitor(strategy);
    if (!generator->createFile("Test.java", "test content"))
        cout << "error writing file" << endl;
    else
        cout << "successfully created file" << endl;


    return 0;
}

