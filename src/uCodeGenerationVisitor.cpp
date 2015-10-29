#include "uCodeGenerationVisitor.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

uCodeGenerationVisitor::uCodeGenerationVisitor()
{
    mAuthor = "";
    mDate = "";
}

uCodeGenerationVisitor::uCodeGenerationVisitor(uLanguageStrategy *language)
{
    mLanguage = language;
}

void uCodeGenerationVisitor::setLanguage(uLanguageStrategy * language)
{
    mLanguage = language;
}

uLanguageStrategy * uCodeGenerationVisitor::getLanguage() const
{
    return mLanguage;
}

void uCodeGenerationVisitor::setFileAttributes(const string &author, const string &date)
{
    mAuthor = author;
    mDate = date;
}

void uCodeGenerationVisitor::visit(uChildClass *childClass)
{
    createFile(childClass->getName() + mLanguage->getFileExtension(), mAuthor, mDate, mLanguage->createFileContent(childClass, childClass->getBaseClass()->getName()));
}

void uCodeGenerationVisitor::visit(uBaseClass *baseClass)
{
    createFile(baseClass->getName() + mLanguage->getFileExtension(), mAuthor, mDate, mLanguage->createFileContent(baseClass));
}

void uCodeGenerationVisitor::visit(uInterface *interfaceClass)
{
    createFile(interfaceClass->getName() + mLanguage->getFileExtension(), mAuthor, mDate, mLanguage->createFileContent(interfaceClass));
}

bool uCodeGenerationVisitor::createFile(string const& name, string const& author, string const& date, string const& content)
{
    ofstream myfile;
    myfile.open(name);
    if (!myfile.is_open())
        return false;

    myfile << getFileHeader(name, author, date);
    myfile << content;
    myfile.close();
    return true;
}

string uCodeGenerationVisitor::getFileHeader(std::string const& fileName, std::string const& author, std::string const& date)
{
    string header = "";
    header += "// ------------------------------------------------------------------\n";
    header += "// File created with uCode - https://github.com/dstoeg/Uml2CodeTool\n";
    header += "// ------------------------------------------------------------------\n";
    header += "// file      : " + fileName + "\n";
    header += "// author    : " + author + "\n";
    header += "// created   : " + date   + "\n";
    header += "// ------------------------------------------------------------------\n\n";

    return header;
}

