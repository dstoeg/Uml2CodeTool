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


TestMain::TestMain()
{

}

void TestMain::execute()
{
    std::cout << "starting tests..." << std::endl << std::endl;

    uInheritableTest test;
    QTest::qExec(&test);

    uParameterTest testP;
    QTest::qExec(&testP);

    uCompositionTest testC;
    QTest::qExec(&testC);

    uButtonTest testButton;
    QTest::qExec(&testButton);

    uClassButtonTest testClassButton;
    QTest::qExec(&testClassButton);

    uInterfaceButtonTest testInterfaceButton;
    QTest::qExec(&testInterfaceButton);

    std::cout << std::endl;
}

