#ifndef ULANGUAGESTRATEGY
#define ULANGUAGESTRATEGY

#include <string>
#include "uMethod.h"
#include "uParameter.h"
#include "uInheritable.h"
#include "uReference.h"

class uLanguageStrategy {

public:
    std::string getFileExtension() const { return mFileExtension;}    
    virtual std::string createFileContent(uInheritable * aClass, std::string const& base = "") {return "";}

protected:
    std::string mFileExtension;
    virtual std::string createMethod(uMethod const& method) {return "";}
    virtual std::string createAttribute(uParameter const& attribute) {return "";}
    virtual std::string createReference(uReference const& reference) {return "";}

};

#endif // ULANGUAGESTRATEGY

