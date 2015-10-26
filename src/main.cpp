#include <iostream>
#include <vector>

#include "uAccess.h"
#include "uParameter.h"
#include "uMethod.h"
#include "uLanguageCpp.h"
#include "uLanguageJava.h"

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

    cout << endl << strategy->createMethod(method) << endl << endl;

    strategy = new uLanguageJava();

    cout << endl << strategy->createMethod(method) << endl << endl;

    return 0;
}

