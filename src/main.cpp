#include <iostream>
#include <vector>

#include "uAccess.h"
#include "uParameter.h"
#include "uMethod.h"

using namespace std;

int main()
{

    vector<uParameter> params;
    params.push_back(uParameter("myint", "int", uPublic));


    uMethod meth("myMethod", "int", uPublic, params);

    cout << meth.getAccess() << " " << meth.getReturnType() << " " << meth.getName() << "();" << endl;


    cout << "Hello World!" << endl;
    return 0;
}

