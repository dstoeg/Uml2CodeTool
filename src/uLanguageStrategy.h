#ifndef ULANGUAGESTRATEGY
#define ULANGUAGESTRATEGY

#include <string>
#include "uMethod.h"

class uLanguageStrategy {

public:
    std::string getFileExtension() const { return mFileExtension;}
    virtual std::string createMethod(uMethod const& method) {return "";}

protected:
    std::string mFileExtension;
};

#endif // ULANGUAGESTRATEGY

