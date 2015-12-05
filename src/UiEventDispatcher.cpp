#include "UiEventDispatcher.h"
#include "uClassFactory.h"
#include "uDebugPrinter.h"

#include <iostream>


using namespace std;

UiEventDispatcher::UiEventDispatcher(QObject *parent) : QObject(parent)
{

}

void UiEventDispatcher::createClass(QString name)
{
    cout << "[log] create class called" << endl;
}

void UiEventDispatcher::createClass(QString name, QString parent, QString methods, QString attributes)
{
    // convert string to objects
    TMethods methodObjects = mConverter.parseMethods(methods.toStdString());
    uDebugPrinter printer;
    printer.printMethod(methodObjects[0]);


    TParameters attributeObjects = mConverter.parseAttributes(attributes.toStdString());

    // call factory to create object


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
    cout << "switched to " << getClassTypeString(mSelectedClassState) << endl;
}

void UiEventDispatcher::generateCode()
{
    cout << "generating code" << endl;
}

