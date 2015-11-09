#include "uParameterTest.h"
#include <QtTest/QtTest>

uParameterTest::uParameterTest(QObject *parent) : QObject(parent)
{

}

void uParameterTest::getNameTest()
{
    QVERIFY(mParam->getName() == "TestParameter");
}

void uParameterTest::initTestCase()
{
    mParam = new uParameter(uAccess::uPrivate, "string", "TestParameter");
}

void uParameterTest::cleanupTestCase()
{
    delete mParam; mParam = NULL;
}
