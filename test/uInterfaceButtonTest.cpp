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
    QVERIFY(mObject->create(eInterface, uPrivate, "Test Class", params, methods, references)
            == new uInterface(uPrivate, "Test Class", params, methods, references));
}

