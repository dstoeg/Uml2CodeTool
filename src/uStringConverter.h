#ifndef USTRINGCONVERTER_H
#define USTRINGCONVERTER_H

#include <string>
#include <vector>
#include "uInheritable.h"
#include "uLanguageStrategy.h"

class uStringConverter
{
public:
    uStringConverter();

    static TMethods parseMethods(std::string const& text);
    static TParameters parseAttributes(std::string const& text);
    static uLanguageStrategy * parseLanguage(std::string const& language);
    static std::string createMethodString(TMethods const& methods);
    static std::string createAttributeString(TParameters const& attributes);

private:
    static std::vector<std::string> splitString(std::string const& text);
    static bool isAccessChar(char c);
};

#endif // USTRINGCONVERTER_H
