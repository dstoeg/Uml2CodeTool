#ifndef UPARAMETER
#define UPARAMETER

#include "uAccess.h"

class uParameter {

public:
    uParameter(uAccess access, std::string const&type, std::string const& name);
    std::string getName() const;
    std::string getType() const;
    uAccess getAccess() const;

private:
    std::string mName;
    std::string mType;
    uAccess mAccess;
};

#endif // UPARAMETER

