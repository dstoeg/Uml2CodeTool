#include "uButtonTest.h"
#include <QtTest/QtTest>

uButtonTest::uButtonTest(QObject *parent) : QObject(parent)
{

}

void uButtonTest::initTestCase()
{
    mObject = &uButton::getInstance();
}

void uButtonTest::cleanupTestCase()
{
}

void uButtonTest::getInstanceTest()
{
    QVERIFY(&(mObject->getInstance()) == mObject);
}

