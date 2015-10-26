#include "uLanguageCpp.h"

using namespace std;

uLanguageCPP::uLanguageCPP()
{
    mFileExtension = ".h";
}


std::string uLanguageCPP::createMethod(const uMethod & method)
{
    string methodStr = "";
    vector<uParameter> params = method.getParameters();
    methodStr += method.getReturnType() + " " + method.getName() + "(";
    for (size_t i=0; i<params.size()-1; ++i) {
        methodStr += params[i].getType() + " " + params[i].getName() + ", ";
    }
    methodStr += params[params.size()-1].getType() + " " + params[params.size()-1].getName() + ");";

    return methodStr;
}

