#ifndef ULANGUAGESTRATEGY
#define ULANGUAGESTRATEGY

#include <string>
#include "uMethod.h"
#include "uParameter.h"
#include "uInheritable.h"
#include "uReference.h"

class uLanguageStrategy {

public:
    std::string getImplementationFileExtension() const { return mImplementationFileExtension;}
    std::string getDeclarationFileExtension() const {return mDeclarationFileExtension; }
    virtual std::string createDeclarationFileContent(uInheritable * aClass, std::string const& base = "") {return "";}
    virtual std::string createImplementationFileContent(uInheritable * aClass, std::string const& base = "") {return "";}
    bool hasSeparateFiles() const {return mHasSeparateFiles; }

protected:
    std::string mImplementationFileExtension;
    std::string mDeclarationFileExtension;
    bool mHasSeparateFiles;

    virtual std::string createMethodDeclaration(uMethod const& method) {return "";}
    virtual std::string createAttributeDeclaration(uParameter const& attribute) {return "";}
    virtual std::string createReferenceDeclaration(uReference const& reference) {return "";}
    virtual std::string createMethodImplementation(uMethod const& method, std::string aClass) {return "";}
};

#endif // ULANGUAGESTRATEGY

