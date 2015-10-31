#ifndef UPARAMETER
#define UPARAMETER

#include "uAccess.h"
#include <vector>
#include <iterator>



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

typedef std::vector<uParameter> TParameters;
typedef std::vector<uParameter>::iterator TParametersIter;

#endif // UPARAMETER

