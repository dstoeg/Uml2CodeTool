#ifndef UMETHOD_H
#define UMETHOD_H

#include <QObject>

#include "uParameter.h"
#include <vector>
#include <iterator>


class uMethod : public QObject
{
    Q_OBJECT
public:
    explicit uMethod(QObject *parent = 0);
    uMethod(uAccess access, std::string const& returnType, std::string const& name, std::vector<uParameter> const& params);
    std::string getName() const;
    std::string getReturnType() const;
    uAccess getAccess() const;
    std::vector<uParameter> getParameters() const;
    inline bool operator==(const uMethod& m2) const;
    inline bool operator!=(const uMethod& m2) const;

private:
    std::string mName;
    std::string mReturnType;
    uAccess mAccess;
    std::vector<uParameter> mParameters;
};


typedef std::vector<uMethod> TMethods;
typedef std::vector<uMethod>::iterator TMethodsIter;
typedef std::vector<uMethod>::const_iterator TMethodsConstIter;

#endif // UMETHOD_H
