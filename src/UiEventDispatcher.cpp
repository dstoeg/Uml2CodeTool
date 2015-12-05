#include "UiEventDispatcher.h"
#include "uClassFactory.h"
#include "uDebugPrinter.h"

using namespace std;

UiEventDispatcher::UiEventDispatcher(QObject *parent) : QObject(parent)
{

}

void UiEventDispatcher::createClass(QString name)
{

}

void UiEventDispatcher::createClass(QString name, QString parent, QString methods, QString attributes)
{
    // convert method string to uMethod objects
    TMethods methodObjects = mConverter.parseMethods(methods.toStdString());

    // convert attribute string to uParameter objects
    TParameters attributeObjects = mConverter.parseAttributes(attributes.toStdString());

    TReferences refs;

    // call factory to create object
    uInheritable * obj = new uBaseClass(uPublic, name.toStdString(), attributeObjects, methodObjects, refs);

    uDebugPrinter::printClass(obj);

    // do something with object
}

void UiEventDispatcher::setClassState(int type)
{
    switch (type) {

        case 0:
            mSelectedClassState = eBaseClass;
            break;
        case 1:
            mSelectedClassState = eInterface;
            break;
        case 2:
            mSelectedClassState = eChildClass;
            break;
        default:
            break;
    }

    // TODO remove
    uDebugPrinter::printText("switched to " + getClassTypeString(mSelectedClassState));
}

void UiEventDispatcher::generateCode()
{
    uDebugPrinter::printText("generating code");
}

