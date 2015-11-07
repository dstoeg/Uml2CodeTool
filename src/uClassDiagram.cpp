#include "uClassDiagram.h"

#include <algorithm>

using namespace std;

uClassDiagram::uClassDiagram()
{
}

void uClassDiagram::addClass(uInheritable *uClass)
{
    mClasses.push_back(uClass);
}

void uClassDiagram::removeClass(uInheritable *uClass)
{
    mClasses.erase(std::remove(mClasses.begin(), mClasses.end(), uClass), mClasses.end());
}

bool uClassDiagram::contains(uInheritable *uClass) const
{
    return std::find(mClasses.begin(), mClasses.end(), uClass) != mClasses.end();
}

uInheritable *uClassDiagram::find(const std::string &name) const
{
    return 0;
}

