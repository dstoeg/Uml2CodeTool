#include "uButtonTest.h"

uButtonTest::uButtonTest(QObject *parent) : QObject(parent)
{

}

void uButtonTest::initTestCase()
{
    mObject = uButton::getInstance();
}

void uButtonTest::cleanupTestCase()
{
    delete mObject; mObject = NULL;
}

void uButtonTest::getInstanceTest()
{
    QVERIFY(mObject->getInstance() == mObject);
}

