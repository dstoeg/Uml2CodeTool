#include "uInheritableTest.h"
#include <QtTest/QtTest>

uInheritableTest::uInheritableTest(QObject *parent) : QObject(parent)
{

}

void uInheritableTest::getNameTest()
{
    QVERIFY(mObject->getName() == "TestClass");
}

void uInheritableTest::initTestCase()
{
    mObject = new uInheritable("TestClass");
}

void uInheritableTest::cleanupTestCase()
{
    delete mObject; mObject = NULL;
}

