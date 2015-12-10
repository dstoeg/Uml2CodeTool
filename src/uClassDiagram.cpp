#include "uClassDiagram.h"

#include <algorithm>
#include "uDebugPrinter.h"
#include "uBaseClass.h"

using namespace std;

uClassDiagram::uClassDiagram()
{

}

uClassDiagram &uClassDiagram::getInstance()
{
    uDebugPrinter::printText("class diagram: get instance called");
    static uClassDiagram mInstance;
    return mInstance;
}

void uClassDiagram::addClass(uInheritable *uClass)
{
    uDebugPrinter::printText("class diagram : adding class");
    uDebugPrinter::printClass(uClass);
    mClasses.push_back(uClass);
}

void uClassDiagram::removeClass(uInheritable *uClass)
{
    uDebugPrinter::printText("class diagram : removing class");
    mClasses.erase(std::remove(mClasses.begin(), mClasses.end(), uClass), mClasses.end());
}

bool uClassDiagram::removeClass(QString const &name)
{
    uDebugPrinter::printText("class diagram : removing class");
    for(TClassesConstIter iter = mClasses.begin(); iter < mClasses.end(); iter++){
        if ((*iter)->getName() == name.toStdString())
            mClasses.erase(std::remove(mClasses.begin(), mClasses.end(), (*iter)), mClasses.end());
            return true;
    }

    return false;

}

bool uClassDiagram::contains(uInheritable *uClass) const
{
    uDebugPrinter::printText("class diagram : contains class called");
    return std::find(mClasses.begin(), mClasses.end(), uClass) != mClasses.end();
}

uInheritable *uClassDiagram::find(QString const &name) const
{
    uDebugPrinter::printText("class diagram : find class called");
    for(TClassesConstIter iter = mClasses.begin(); iter < mClasses.end(); iter++){
        if ((*iter)->getName() == name.toStdString())
            uDebugPrinter::printText("class diagram : find class succeeded");
            return (*iter);
    }
    uDebugPrinter::printText("class diagram : find class failed");
    return 0;
}

void uClassDiagram::applyVisitor(uVisitor *visitor)
{
    uDebugPrinter::printText("applying visitor");
    uDebugPrinter::printText("size: " + to_string(mClasses.size()));

    for(TClassesIter iter = mClasses.begin(); iter < mClasses.end(); iter++){
        (*iter)->accept(visitor);
    }

}

uInheritable *uClassDiagram::get(int index) const
{
    if (index >= mClasses.size()) {
        uDebugPrinter::printText("class diagram : get class failed");
        return NULL;

    }
    uDebugPrinter::printText("class diagram : get class succeeded");
    return mClasses[index];
}

int uClassDiagram::size() const
{
    uDebugPrinter::printText("class diagram : get size called");
    return mClasses.size();
}

int uClassDiagram::getIndex(const QString &name)
{
    for (size_t i=0; i<mClasses.size(); i++) {
        if (mClasses[i]->qGetName() == name) return i;
    }
    return -1;
}
