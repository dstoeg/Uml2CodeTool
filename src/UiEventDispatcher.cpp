#include "UiEventDispatcher.h"
#include "uDebugPrinter.h"
#include "uClassType.h"


using namespace std;


UiEventDispatcher::UiEventDispatcher(QObject *parent) : QObject(parent)
{
    mCodeGenerator = &uCodeGenerationVisitor::getInstance();
    mClassDiagram = new uClassDiagram();
    mFactory = &uClassFactory::getInstance();
    // Needs a default state
    mSelectedClassState = eInterface;
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

    TReferences refs;

    // TODO find parent given name
    // TODO replace with found parent class
    uInheritable * testBase;

    // call factory to create object
    obj = mFactory->createClass(mSelectedClassState, uPublic, name.toStdString(), attributeObjects, methodObjects, refs, testBase);

//    uDebugPrinter::printClass(obj);

    // do something with object
    mClassDiagram->addClass(obj);
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

