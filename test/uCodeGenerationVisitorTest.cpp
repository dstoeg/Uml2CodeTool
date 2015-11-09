#include "uCodeGenerationVisitorTest.h"
#include "src/uLanguageJava.h"
#include <QtTest/QtTest>

uCodeGenerationVisitorTest::uCodeGenerationVisitorTest(QObject *parent) : QObject(parent)
{

}

void uCodeGenerationVisitorTest::initTestCase()
{
    mObject = &uCodeGenerationVisitor::getInstance();
}

void uCodeGenerationVisitorTest::cleanupTestCase()
{

}

void uCodeGenerationVisitorTest::setGetLanguageTest()
{
    uLanguageStrategy * java = new uLanguageJava();
    mObject->setLanguage(java);
    QVERIFY(mObject->getLanguage()->getName() == "Java");
}

