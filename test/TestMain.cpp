#include "TestMain.h"
#include <QtTest/QtTest>
#include <string>
#include <iostream>

#include "test/uInheritableTest.h"
#include "test/uParameterTest.h"
#include "test/uCompositionTest.h"


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

    std::cout << std::endl;
}

