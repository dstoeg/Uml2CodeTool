#include "uClassButtonTest.h"
#include <QtTest/QtTest>

uClassButtonTest::uClassButtonTest(QObject *parent) : QObject(parent)
{

}

void uClassButtonTest::initTestCase()
{
    mObject = &uClassButton::getInstance();
}

void uClassButtonTest::cleanupTestCase()
{
    delete mObject; mObject = NULL;
}

void uClassButtonTest::getInstanceTest()
{
    QVERIFY(&(mObject->getInstance()) == mObject);
}

void uClassButtonTest::createTest()
{
    TParameters params;
    TMethods methods;
    TReferences references;
    QVERIFY(mObject->create(eBaseClass, uPrivate, "Test Class", params, methods, references, NULL)
            == new uBaseClass(uPrivate, "Test Class", params, methods, references));
}

