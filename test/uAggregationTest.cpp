#include "uAggregationTest.h"
#include "src/uInheritable.h"
#include <QtTest/QtTest>

uAggregationTest::uAggregationTest(QObject *parent) : QObject(parent)
{

}

void uAggregationTest::initTestCase()
{
        uInheritable * reference = new uInheritable("TestReference");
        mObject = new uAggregation(reference, uAccess::uPublic);
}


void uAggregationTest::cleanupTestCase()
{
    delete(mObject); mObject = NULL;
}

void uAggregationTest::getAccessTest()
{
    QVERIFY(mObject->getAccess() == uAccess::uPublic);
}

void uAggregationTest::getReferenceSymbolTest()
{
    QVERIFY(mObject->getReferenceSymbol() == "*");
}

void uAggregationTest::getClassTest()
{
    QVERIFY(mObject->getClass() == new uInheritable("TestReference"));
}

