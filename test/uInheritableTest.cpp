#include "uInheritableTest.h"
#include <QtTest/QtTest>

uInheritableTest::uInheritableTest(QObject *parent) : QObject(parent)
{

}

void uInheritableTest::getNameTest()
{
    QVERIFY(mObject->getName() == "TestClass");
}

//void uInheritableTest::getMethodsTest()
//{
//    TParameters methodParams = {uParameter(uPrivate , "int", "param1"), uParameter(uPrivate , "string", "param2"), uParameter(uPrivate , "float", "param3")};
//    uMethod method( uPublic, "void", "draw", methodParams);
//    TMethods methods = {method};
//    QVERIFY(mObject->getMethods() == methods);
//}

//void uInheritableTest::getAttributesTest()
//{
//    TParameters parameters = {uParameter(uPrivate , "int", "id"),uParameter(uProtected , "string", "name"), uParameter(uPublic , "float", "size")};
//    QVERIFY(mObject->getAttributes() == parameters);
//}

void uInheritableTest::getReferencesTest()
{
    TReferences references;
    QVERIFY(mObject->getReferences() == references);
}

void uInheritableTest::getAccessTest()
{
    QVERIFY(mObject->getAccess() == uPublic);
}

void uInheritableTest::setAccessTest()
{
    mObject->setAccess(uPrivate);
    QVERIFY(mObject->getAccess() == uPrivate);
    mObject->setAccess(uPublic);
}

//void uInheritableTest::hasParentTest()
//{
//    QVERIFY(mObject->hasParent() == false);
//}

void uInheritableTest::initTestCase()
{
    TParameters methodParams = {new uParameter(uPrivate , "int", "param1"),new uParameter(uPrivate , "string", "param2"),new uParameter(uPrivate , "float", "param3")};
    uMethod *method = new uMethod( uPublic, "void", "draw", methodParams);
    TParameters parameters = {new uParameter(uPrivate , "int", "id"),new uParameter(uProtected , "string", "name"),new uParameter(uPublic , "float", "size")};
    TMethods methods = {method};
    TReferences references;
    mObject = new uInheritable(uPublic,"TestClass", parameters, methods, references);
}

void uInheritableTest::cleanupTestCase()
{
    delete mObject; mObject = NULL;
}

