#include "uLanguagePython.h"

using namespace std;

uLanguagePython::uLanguagePython()
{
    mFileExtension = ".py";
}


std::string uLanguagePython::createMethod(const uMethod & method)
{
    return "";
}

string uLanguagePython::createAttribute(const uParameter &attribute)
{
    return "";
}

string uLanguagePython::createReference(const uReference &reference)
{
    return "";
}

string uLanguagePython::createFileContent(uInheritable * aClass, std::string const& base)
{
    return "";   
}

