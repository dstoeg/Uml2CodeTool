#include "TestMain.h"
#include <QtTest/QtTest>
#include <string>
#include <iostream>

#include "test/uInheritableTest.h"



TestMain::TestMain()
{

}

void TestMain::execute()
{
    std::cout << "starting tests..." << std::endl << std::endl;
    uInheritableTest test;
    QTest::qExec(&test);
    std::cout << std::endl;
}

