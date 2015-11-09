#include "uLanguageCppTest.h"
#include "src/uBaseClass.h"
#include <QtTest/QtTest>
#include <string>
#include <iostream>

using namespace std;

uLanguageCppTest::uLanguageCppTest(QObject *parent) : QObject(parent)
{

}

void uLanguageCppTest::initTestCase()
{
    mObject = new uLanguageCPP();
}

void uLanguageCppTest::cleanupTestCase()
{
    delete mObject; mObject = NULL;
}

void uLanguageCppTest::getImplementationFileExtensionTest()
{
    QVERIFY(mObject->getImplementationFileExtension() == ".cpp");
}

void uLanguageCppTest::getDeclarationFileExtensionTest()
{
    QVERIFY(mObject->getDeclarationFileExtension() == ".h");
}

void uLanguageCppTest::createDeclarationFileContentTest()
{
    // TODO
}

void uLanguageCppTest::createImplementationFileContentTest()
{
    // TODO
}

void uLanguageCppTest::hasSeparateFilesTest()
{
    QVERIFY(mObject->hasSeparateFiles() == true);
}

void uLanguageCppTest::getLineCommentTest()
{
    QVERIFY(mObject->getLineComment() == "//");
}

void uLanguageCppTest::getNameTest()
{
    QVERIFY(mObject->getName() == "C++");
}

