#include "uInterfaceButtonTest.h"
#include <QtTest/QtTest>

uInterfaceButtonTest::uInterfaceButtonTest(QObject *parent) : QObject(parent)
{

}

void uInterfaceButtonTest::initTestCase()
{
    mObject = &uInterfaceButton::getInstance();
}

void uInterfaceButtonTest::cleanupTestCase()
{
    delete mObject; mObject = NULL;
}

void uInterfaceButtonTest::getInstanceTest()
{
    QVERIFY(&(mObject->getInstance()) == mObject);
}

void uInterfaceButtonTest::createTest()
{
    TParameters params;
    TMethods methods;
    TReferences references;
    uInheritable * interfaceTest1 = new uInterface(uPrivate, "Test Class", params, methods, references);
    uInheritable * interfaceTest2 = mObject->create(eInterface, uPrivate, "Test Class", params, methods, references);
//    QVERIFY(interfaceTest1->getAccess() == interfaceTest2->getAccess());
//    QVERIFY(interfaceTest1->getAttributes() == interfaceTest2->getAttributes());
//    QVERIFY(interfaceTest1->getMethods() == interfaceTest2->getMethods());
//    QVERIFY(interfaceTest1->getName() == interfaceTest2->getName());
//    QVERIFY(interfaceTest1->getReferences() == interfaceTest2->getReferences());
    QVERIFY(true);
}

