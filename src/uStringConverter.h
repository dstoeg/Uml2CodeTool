#ifndef USTRINGCONVERTER_H
#define USTRINGCONVERTER_H

#include <string>
#include <vector>
#include <QString>

#include "uInheritable.h"
#include "uLanguageStrategy.h"
#include "uProjectFile.h"

class uStringConverter
{
public:
    explicit uStringConverter();

    static TMethods parseMethods(std::string const& text);
    static TParameters parseAttributes(std::string const& text);
    static uLanguageStrategy * parseLanguage(std::string const& language);
    static uProjectFile * parseDevEnv(std::string const& devenv);
    static std::string createMethodString(TMethods const& methods);
    static std::string createAttributeString(TParameters const& attributes);
    static uAccess dAccess;

    // qml functions
    static QString qCreateMethodString(TMethods const& methods);
    static QString qCreateMethodStringFromClass(uInheritable * obj);
    static QString qCreateAttributeString(TParameters const& attributes);
    static QString qCreateAttributeStringFromClass(uInheritable * obj);

private:
    static std::vector<std::string> splitString(std::string const& text);
    static bool isAccessChar(char c);
};

#endif // USTRINGCONVERTER_H
