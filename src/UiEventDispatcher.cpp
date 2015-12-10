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
<<<<<<< HEAD
    mClassDiagram = &uClassDiagram::getInstance();
    mFactory = &uClassFactory::getInstance();
=======
    mClassDiagram = new uClassDiagram();
>>>>>>> 20ba91d0e9fd39f1989cb5ea85163adfa2943ba0
    mClassButton = &uClassButton::getInstance();
}

void UiEventDispatcher::createClass(QString name)
{

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
    mClassDiagram->addClass(obj);
    cout << "diagram size after: " << mClassDiagram->size() << endl;
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

