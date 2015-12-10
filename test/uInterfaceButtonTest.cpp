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
}

void uInterfaceButtonTest::getInstanceTest()
{
    QVERIFY(&(mObject->getInstance()) == mObject);
}

void uInterfaceButtonTest::createTest()
{
    /*
    TParameters params;
    TMethods methods;
    TReferences references;
    uInheritable * interfaceTest1 = new uInterface(uPrivate, "Test Class", params, methods, references);
    uInheritable * interfaceTest2 = mObject->create(uPrivate, "Test Class", params, methods, references);
    QVERIFY(interfaceTest1 == interfaceTest2);
    */

}

