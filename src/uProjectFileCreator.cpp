#include "uProjectFileCreator.h"
#include "uDebugPrinter.h"
#include "uProjectFileQT.h"

#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;


uProjectFileCreator::uProjectFileCreator()
{
    mDevenv = new uProjectFileQT();
}

void uProjectFileCreator::createFile(uClassDiagram const * const diagram)
{
    string content = mDevenv->createFile(diagram);
    generateFile(content);
}

void uProjectFileCreator::setDevEnv(uProjectFile *devenv)
{
    mDevenv = devenv;
}

std::string uProjectFileCreator::getDevEnvString() const
{
    if (mDevenv == NULL) {
        uDebugPrinter::printText("NULL OBJECT");
        return "";
    }
    return mDevenv->getName();
}

bool uProjectFileCreator::generateFile(const string &content)
{
    ofstream myfile;
    myfile.open("Test.pro");
    if (!myfile.is_open())
        return false;

    myfile << content;
    myfile.close();
    return true;
}

