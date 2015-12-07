#include "uMethod.h"


uMethod::uMethod(QObject *parent) : QObject(parent)
{

}

uMethod::uMethod(uAccess access, std::string const& returnType, std::string const& name, TParameters const& params) : QObject(0)
{
    mName = name;
    mReturnType = returnType;
    mAccess = access;
    mParameters = params;
}

std::string uMethod::getName() const
{
    return mName;
}

std::string uMethod::getReturnType() const
{
    return mReturnType;
}

uAccess uMethod::getAccess() const
{
    return mAccess;
}

std::vector<uParameter *> uMethod::getParameters() const
{
    return mParameters;
}

inline bool uMethod::operator==(const uMethod &m2) const
{
    return mAccess==m2.getAccess() && mName==m2.getName() && mReturnType==m2.getReturnType() && mParameters==m2.getParameters();
}

inline bool uMethod::operator!=(const uMethod &m2) const
{
    return !operator==(m2);
}

static bool operator==(TMethods& methods1, TMethods& methods2){
    if(methods1.size()!=methods2.size())
        return false;

    TMethodsIter iter2 = methods2.begin();
    for (TMethodsIter iter1 = methods1.begin(); iter1 != methods1.end(); iter1++, iter2++ ){
        if((*iter1)!=(*iter2))
            return false;
    }

    return true;
}
