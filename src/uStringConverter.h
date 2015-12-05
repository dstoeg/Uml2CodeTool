#ifndef USTRINGCONVERTER_H
#define USTRINGCONVERTER_H

#include <string>
#include <vector>
#include "uInheritable.h"

class uStringConverter
{
public:
    uStringConverter();

    TMethods parseMethods(std::string const& text);
    TParameters parseAttributes(std::string const& text);

    std::string createMethodString(TMethods const& methods);
    std::string createAttributeString(TParameters const& attributes);

private:
    std::vector<std::string> splitString(std::string const& text);
    bool isAccessChar(char c) const;
};

#endif // USTRINGCONVERTER_H
