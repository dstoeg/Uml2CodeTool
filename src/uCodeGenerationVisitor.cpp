#include "uCodeGenerationVisitor.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "uDebugPrinter.h"

using namespace std;



uCodeGenerationVisitor::uCodeGenerationVisitor()
{
    mAuthor = "";
    mDate = "";
}

uCodeGenerationVisitor &uCodeGenerationVisitor::getInstance()
{
    static uCodeGenerationVisitor instance;
    return instance;
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
    if (mLanguage->hasSeparateFiles()) {
        createFile(childClass->getName() + mLanguage->getImplementationFileExtension(), mAuthor, mDate, mLanguage->createImplementationFileContent(childClass, childClass->getBaseClass()->getName()), mLanguage->getLineComment());
        cout << "    " << childClass->getName() + mLanguage->getImplementationFileExtension() << endl;
    }
    createFile(childClass->getName() + mLanguage->getDeclarationFileExtension(), mAuthor, mDate, mLanguage->createDeclarationFileContent(childClass, childClass->getBaseClass()->getName()), mLanguage->getLineComment());
    cout << "    " << childClass->getName() + mLanguage->getDeclarationFileExtension() << endl;
}

void uCodeGenerationVisitor::visit(uBaseClass *baseClass)
{
    if (mLanguage->hasSeparateFiles()) {
        createFile(baseClass->getName() + mLanguage->getImplementationFileExtension(), mAuthor, mDate, mLanguage->createImplementationFileContent(baseClass), mLanguage->getLineComment());
        cout << "    " << baseClass->getName() + mLanguage->getImplementationFileExtension() << endl;
    }
    createFile(baseClass->getName() + mLanguage->getDeclarationFileExtension(), mAuthor, mDate, mLanguage->createDeclarationFileContent(baseClass), mLanguage->getLineComment());
    cout << "    " << baseClass->getName() + mLanguage->getDeclarationFileExtension() << endl;
}

void uCodeGenerationVisitor::visit(uInterface *interfaceClass)
{
    if (mLanguage->hasSeparateFiles()) {
        createFile(interfaceClass->getName() + mLanguage->getImplementationFileExtension(), mAuthor, mDate, mLanguage->createImplementationFileContent(interfaceClass), mLanguage->getLineComment());
        cout << "    " << interfaceClass->getName() + mLanguage->getImplementationFileExtension() << endl;
    }
    createFile(interfaceClass->getName() + mLanguage->getDeclarationFileExtension(), mAuthor, mDate, mLanguage->createDeclarationFileContent(interfaceClass), mLanguage->getLineComment());
    cout << "    " << interfaceClass->getName() + mLanguage->getDeclarationFileExtension() << endl;
}

bool uCodeGenerationVisitor::createFile(string const& name, string const& author, string const& date, string const& content, string const& lineComment, string const& path)
{
    ofstream myfile;
    myfile.open(path+name.c_str());
    if (!myfile.is_open())
        return false;

    myfile << getFileHeader(name, author, date, lineComment);
    myfile << content;
    myfile.close();
    return true;
}

string uCodeGenerationVisitor::getFileHeader(std::string const& fileName, std::string const& author, std::string const& date, std::string const& lineComment)
{
    string header = "";
    header += lineComment + " ------------------------------------------------------------------\n";
    header += lineComment + " File created with uCode - https://github.com/dstoeg/Uml2CodeTool\n";
    header += lineComment + " ------------------------------------------------------------------\n";
    header += lineComment + " file      : " + fileName + "\n";
    header += lineComment + " author    : " + author + "\n";
    header += lineComment + " created   : " + date   + "\n";
    header += lineComment + " ------------------------------------------------------------------\n\n";

    return header;
}
