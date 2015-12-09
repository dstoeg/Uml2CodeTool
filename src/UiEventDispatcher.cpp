#include "UiEventDispatcher.h"
#include "uDebugPrinter.h"
#include "uClassType.h"
#include "uClassButton.h"
#include "uInterfaceButton.h"
#include "uChildButton.h"


using namespace std;


UiEventDispatcher::UiEventDispatcher(QObject *parent) : QObject(parent)
{
    mCodeGenerator = &uCodeGenerationVisitor::getInstance();
    mClassDiagram = new uClassDiagram();
    mFactory = &uClassFactory::getInstance();
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
    mClassDiagram->addClass(obj);
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

