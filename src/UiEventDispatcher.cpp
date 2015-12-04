#include "UiEventDispatcher.h"
#include "uClassFactory.h"

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
    cout << "[log] creating class:" << endl;
    cout << "name: " << name.toStdString() << endl;
    cout << "parent: " << parent.toStdString() << endl;
    cout << "methods: " << methods.toStdString() << endl;
    cout << "attributes: " << attributes.toStdString() << endl;

    // convert string to objects
    TMethods methodObjects = mConverter.parseMethods(methods.toStdString());
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

