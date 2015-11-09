#include "uMethodTest.h"
#include "uParameterTest.h"
#include <QtTest/QtTest>

uMethodTest::uMethodTest(QObject *parent) : QObject(parent)
{

}

void uMethodTest::getNameTest()
{
    QVERIFY(mMethod->getName()=="TestMethod");
}

void uMethodTest::getAccessTest()
{
    QVERIFY(mMethod->getAccess()== uAccess::uPrivate);
}

void uMethodTest::getReturnTypeTest()
{
    QVERIFY(mMethod->getReturnType() == "void");
}

void uMethodTest::getParametersTest()
{
    // TODO compare vector of structs
    TParameters params;
    params.push_back(uParameter(uPrivate, "string", "param1"));
//    QCOMPARE(mMethod->getParameters(), params);
}

void uMethodTest::initTestCase()
{
    // do objects need to be explicitly declared or can they be
//    passed by functions anonymously?
    TParameters params;
    params.push_back(uParameter(uPrivate, "string", "param1"));
    mMethod = new uMethod(uAccess::uPrivate, "void", "TestMethod",
    params);
}

void uMethodTest::cleanupTestCase()
{
    delete(mMethod); mMethod = NULL;
}
