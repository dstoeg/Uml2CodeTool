#ifndef ULANGUAGESTRATEGY
#define ULANGUAGESTRATEGY

#include <string>
#include "uMethod.h"
#include "uParameter.h"

class uLanguageStrategy {

public:
    std::string getFileExtension() const { return mFileExtension;}
    virtual std::string createMethod(uMethod const& method) {return "";}
    virtual std::string createAttribute(uParameter const& attribute) {return "";}

protected:
    std::string mFileExtension;
};

#endif // ULANGUAGESTRATEGY

