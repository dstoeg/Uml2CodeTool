#ifndef UCODEGENERATIONVISITOR_H
#define UCODEGENERATIONVISITOR_H

#include "uVisitor.h"
#include "uLanguageStrategy.h"

class uCodeGenerationVisitor : public uVisitor
{
public:
    uCodeGenerationVisitor();
    uCodeGenerationVisitor(uLanguageStrategy * language);
    void setLanguage(uLanguageStrategy * language);
    uLanguageStrategy * getLanguage() const;
    void setFileAttributes(std::string const& author, std::string const& date);

    virtual void visit(uChildClass * childClass);
    virtual void visit(uBaseClass * baseClass);
    virtual void visit(uInterface * interfaceClass);

    bool createFile(std::string const& name, std::string const& author, std::string const& date, std::string const& content, std::string const& lineComment);


private:
    uLanguageStrategy * mLanguage;

    std::string mAuthor;
    std::string mDate;

    std::string getFileHeader(std::string const& fileName, std::string const& author, std::string const& date, std::string const& lineComment);

};

#endif // UCODEGENERATIONVISITOR_H
