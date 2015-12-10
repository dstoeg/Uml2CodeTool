#include "UiEventDispatcher.h"
#include "uDebugPrinter.h"
#include "uClassType.h"
#include "uClassButton.h"
#include "uInterfaceButton.h"
#include "uChildButton.h"
#include "uStringConverter.h"



using namespace std;


UiEventDispatcher::UiEventDispatcher(QObject *parent) : QObject(0)
{
    mCodeGenerator = &uCodeGenerationVisitor::getInstance();
    mClassDiagram = &uClassDiagram::getInstance();
    mClassButton = &uClassButton::getInstance();
}

void UiEventDispatcher::createClass(QString name, QString parent, QString methods, QString attributes)
{
    // convert method string to uMethod objects
    TMethods methodObjects = uStringConverter::parseMethods(methods.toStdString());

    // convert attribute string to uParameter objects
    TParameters attributeObjects = uStringConverter::parseAttributes(attributes.toStdString());

    // TODO
    TReferences referenceObjects;

    // find parent given name
    uInheritable * parentObj = mClassDiagram->find(parent);

    // call factory to create object
    mClassButton->create(uPublic, name.toStdString(), attributeObjects, methodObjects, referenceObjects, parentObj);
}

void UiEventDispatcher::updateClass(QString oldName, QString newName, QString parent, QString methods, QString attributes)
{
    // convert method string to uMethod objects
    TMethods methodObjects = uStringConverter::parseMethods(methods.toStdString());

    // convert attribute string to uParameter objects
    TParameters attributeObjects = uStringConverter::parseAttributes(attributes.toStdString());

    // TODO
    TReferences referenceObjects;

    // find parent given name
    uInheritable * parentObj = mClassDiagram->find(parent);

    // call factory to create object
    mClassButton->update(oldName.toStdString(), uPublic, newName.toStdString(), attributeObjects, methodObjects, referenceObjects, parentObj);
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
    uDebugPrinter::printText("done generating code");
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

void UiEventDispatcher::removeClass(uInheritable *obj)
{
    if (obj == NULL) return;
    mClassDiagram->removeClass(obj);
}

void UiEventDispatcher::removeClass(QString name)
{
    uInheritable * obj = mClassDiagram->find(name);
    if (obj != NULL) {
        mClassDiagram->removeClass(obj);
    }
}

QString UiEventDispatcher::getClassName(int index)
{
    uInheritable * obj = getClass(index);
    if (obj == NULL) return "";

    return QString::fromStdString(obj->getName());
}

QString UiEventDispatcher::getClassMethods(int index)
{
    uInheritable * obj = getClass(index);
    if (obj == NULL) return "";

    return uStringConverter::qCreateMethodStringFromClass(obj);
}

QString UiEventDispatcher::getClassAttributes(int index)
{
    uInheritable * obj = getClass(index);
    if (obj == NULL) return "";

    return uStringConverter::qCreateAttributeStringFromClass(obj);
}

int UiEventDispatcher::getClassIndex(QString name)
{
    uInheritable * obj = mClassDiagram->find(name);
    if (obj == NULL) return -1;

    return mClassDiagram->getIndex(name);

}

QString UiEventDispatcher::getClassParent(int index)
{
    uInheritable * obj = getClass(index);
    if (obj == NULL || !obj->hasParent()) {
        return "";
    }
    uInheritable * parent = obj->getParent();
    if (parent == NULL) {
        return "";
    }

    return QString::fromStdString(parent->getName());
}

int UiEventDispatcher::getClassReferenceCount(QString name)
{
    uInheritable * obj = mClassDiagram->find(name);
    if (obj == NULL) return 0;
    return generateReferences(obj).size();
}

QString UiEventDispatcher::getClassReference(QString name, int index)
{
    uInheritable * obj = mClassDiagram->find(name);
    if (obj == NULL) return "";

    std::vector<QString> references = generateReferences(obj);
    if (index >= references.size()) return "";

    return references[index];
}

std::vector<QString> UiEventDispatcher::generateReferences(uInheritable * obj)
{
    std::vector<QString> references;
    TParameters attributes = obj->getAttributes();
    for (TParametersIter iter = attributes.begin(); iter != attributes.end(); ++iter) {
        if (mClassDiagram->contains((*iter)->getType())) {
            references.push_back(QString::fromStdString((*iter)->getType()));
        }
    }
    return references;
}

