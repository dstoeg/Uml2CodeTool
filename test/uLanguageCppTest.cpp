#include "uLanguageCppTest.h"
#include <QtTest/QtTest>

uLanguageCppTest::uLanguageCppTest(QObject *parent) : QObject(parent)
{

}

void uLanguageCppTest::initTestCase()
{
    mObject = new uLanguageCPP();
}

void uLanguageCppTest::cleanupTestCase()
{

}

void uLanguageCppTest::getImplementationFileExtensionTest()
{
    QVERIFY(mObject->getImplementationFileExtension() == ".cpp");
}

