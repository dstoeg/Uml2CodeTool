#include "uReferenceTest.h"
#include "src/uInheritable.h"
#include <QtTest/QtTest>

uReferenceTest::uReferenceTest(QObject *parent) : QObject(parent)
{

}

void uReferenceTest::initTestCase()
{
        uInheritable * reference = new uInheritable("TestReference");
        mObject = new uReference(reference, uAccess::uPublic);
}


void uReferenceTest::cleanupTestCase()
{
    delete(mObject); mObject = NULL;
}

void uReferenceTest::getAccessTest()
{
    QVERIFY(mObject->getAccess() == uAccess::uPublic);
}

void uReferenceTest::getReferenceSymbolTest()
{
    QVERIFY(mObject->getReferenceSymbol() == "");
}

void uReferenceTest::getClassTest()
{
    QVERIFY(mObject->getClass() == new uInheritable("TestReference"));
}


