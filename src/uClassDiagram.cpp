#include "uClassDiagram.h"

#include <algorithm>
#include "uDebugPrinter.h"

using namespace std;

uClassDiagram::uClassDiagram(QObject *parent) : QObject(parent)
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

uInheritable *uClassDiagram::find(QString const &name) const
{
    for(TClassesConstIter iter = mClasses.begin(); iter < mClasses.end(); iter++){
        if ((*iter)->getName() == name.toStdString())
            return (*iter);
    }
    return 0;
}

void uClassDiagram::applyVisitor(uVisitor *visitor)
{
        uDebugPrinter::printText("applying visitor");
    for(TClassesIter iter = mClasses.begin(); iter < mClasses.end(); iter++){
        (*iter)->accept(visitor);
    }
}

uInheritable *uClassDiagram::get(int index) const
{
    if (index >= mClasses.size()) return NULL;
    return mClasses[index];
}

int uClassDiagram::size() const
{
    return mClasses.size();
}


