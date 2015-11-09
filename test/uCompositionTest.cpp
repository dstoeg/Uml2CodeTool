#include "uCompositionTest.h"
#include <QtTest/QtTest>

uCompositionTest::uCompositionTest(QObject *parent) : QObject(parent)
{

}

void uCompositionTest::initTestCase()
{
    mObject = new uComposition(NULL, uPrivate);
}

void uCompositionTest::cleanupTestCase()
{
    delete mObject; mObject = NULL;
}

void uCompositionTest::getReferenceSymbolTest()
{
    QVERIFY(mObject->getReferenceSymbol() == " ");
}

