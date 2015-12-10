#include "UiEventDispatcher.h"
#include "uDebugPrinter.h"
#include "uClassType.h"
#include "uClassButton.h"
#include "uInterfaceButton.h"
#include "uChildButton.h"

#include <iostream>


using namespace std;


UiEventDispatcher::UiEventDispatcher(QObject *parent) : QObject(parent)
{
    mCodeGenerator = &uCodeGenerationVisitor::getInstance();
    mClassDiagram = &uClassDiagram::getInstance();
    mClassButton = &uClassButton::getInstance();
}

void UiEventDispatcher::createClass(QString name, QString parent, QString methods, QString attributes)
{
    uInheritable * obj;
    // convert method string to uMethod objects
    TMethods methodObjects = uStringConverter::parseMethods(methods.toStdString());

    // convert attribute string to uParameter objects
    TParameters attributeObjects = uStringConverter::parseAttributes(attributes.toStdString());

    // TODO
    TReferences referenceObjects;

    // TODO find parent given name
    // TODO replace with found parent class
    uInheritable * testBase;

    // call factory to create object
    obj = mClassButton->create(uPublic, name.toStdString(), attributeObjects, methodObjects, referenceObjects, testBase);

    uDebugPrinter::printClass(obj);

    // do something with object
    cout << "diagram size before: " << mClassDiagram->size() << endl;
    cout << "diagram size after: " << mClassDiagram->size() << endl;
}

void UiEventDispatcher::updateClass(QString oldName, QString newName, QString parent, QString methods, QString attributes)
{
    // convert method string to uMethod objects
    TMethods methodObjects = uStringConverter::parseMethods(methods.toStdString());

    // convert attribute string to uParameter objects
    TParameters attributeObjects = uStringConverter::parseAttributes(attributes.toStdString());

    // TODO
    TReferences referenceObjects;

    // TODO find parent given name
    // TODO replace with found parent class
    uInheritable * testBase;

    // call factory to create object
    mClassButton->update(oldName.toStdString(), uPublic, newName.toStdString(), attributeObjects, methodObjects, referenceObjects, testBase);

    uDebugPrinter::printText("Updated: " + oldName.toStdString());

    // do something with object
    cout << "Updating: diagram size before: " << mClassDiagram->size() << endl;
    cout << "Updating: diagram size after: " << mClassDiagram->size() << endl;
}

void UiEventDispatcher::setClassState(int type)
{
    switch (type) {

        case 0:
            mClassButton = &uClassButton::getInstance();
            break;
        case 1:
            mClassButton = &uInterfaceButton::getInstance();
            break;
        case 2:
            mClassButton = &uChildButton::getInstance();
            break;
        default:
            break;
    }
}

void UiEventDispatcher::setLanguage(QString language)
{
    uDebugPrinter::printText("set language called " + language.toStdString());
    mCodeGenerator->setLanguage(uStringConverter::parseLanguage(language.toStdString()));
}

void UiEventDispatcher::generateCode()
{
     cout << "diagram size: " << mClassDiagram->size() << endl;

    uDebugPrinter::printText("generating code");
    uDebugPrinter::printText("language: " + mCodeGenerator->getLanguage()->getName());

    // TODO
    mCodeGenerator->setFileAttributes("", "");



    mClassDiagram->applyVisitor(mCodeGenerator);
}

uClassDiagram * UiEventDispatcher::getClassDiagram()
{
    return mClassDiagram;
}

int UiEventDispatcher::getDiagramSize()
{
    return mClassDiagram->size();
}

uInheritable *UiEventDispatcher::getClass(int index)
{
    if (!(index < mClassDiagram->size())) return NULL;
    return mClassDiagram->get(index);
}

uInheritable *UiEventDispatcher::findClass(QString name)
{
    return mClassDiagram->find(name);
}

void UiEventDispatcher::removeClass(uInheritable *obj)
{
    mClassDiagram->removeClass(obj);
}

