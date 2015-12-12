#include "uProjectFileQT.h"

#include "uDebugPrinter.h"
#include <sstream>

using namespace std;

uProjectFileQT::uProjectFileQT()
{

}

std::string uProjectFileQT::createFile(uClassDiagram const * const diagram)
{
    if (diagram == NULL) return "";

    stringstream  content;
    string sources = "SOURCES += ";
    string headers = "HEADERS += ";

    content << "TEMPLATE = app" << endl << endl;

    for (size_t i =0; i<diagram->size(); i++) {
        string name = diagram->get(i)->getName();
        sources += name + ".cpp \\ \n";
        headers += name + ".h \\ \n";
    }

    content << headers << endl << endl;

    content << sources << endl << endl;

    return content.str();
}

std::string uProjectFileQT::getName()
{
    return "QtCreator";
}

