#include "TestMain.h"
#include <QtTest/QtTest>
#include <string>
#include <iostream>

#include "test/uInheritableTest.h"
#include "test/uParameterTest.h"
#include "test/uCompositionTest.h"
#include "test/uButtonTest.h"
#include "test/uClassButtonTest.h"
#include "test/uInterfaceButtonTest.h"
#include "test/uCodeGenerationVisitorTest.h"
#include "test/uLanguageCppTest.h"


TestMain::TestMain()
{

}

void TestMain::execute()
{
    std::cout << "starting tests..." << std::endl << std::endl;

    uInheritableTest test1;
    QTest::qExec(&test1);

    uParameterTest test2;
    QTest::qExec(&test2);

    uCompositionTest test3;
    QTest::qExec(&test3);

    uCodeGenerationVisitorTest  test4;
    QTest::qExec(&test4);

    uLanguageCppTest test5;
    QTest::qExec(&test5);

    uButtonTest testButton;
    QTest::qExec(&testButton);

    uClassButtonTest testClassButton;
    QTest::qExec(&testClassButton);

    uInterfaceButtonTest testInterfaceButton;
    QTest::qExec(&testInterfaceButton);

    std::cout << std::endl;
}

