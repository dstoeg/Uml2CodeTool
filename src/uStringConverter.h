#ifndef USTRINGCONVERTER_H
#define USTRINGCONVERTER_H

#include <string>
#include <vector>
#include <QObject>
#include <QString>

#include "uInheritable.h"
#include "uLanguageStrategy.h"

class uStringConverter : public QObject
{
    Q_OBJECT
public:
    explicit uStringConverter(QObject *parent = 0);

    static TMethods parseMethods(std::string const& text);
    static TParameters parseAttributes(std::string const& text);
    static uLanguageStrategy * parseLanguage(std::string const& language);
    static std::string createMethodString(TMethods const& methods);
    static std::string createAttributeString(TParameters const& attributes);

    // qml functions
    Q_INVOKABLE QString qCreateMethodString(TMethods const& methods);
    Q_INVOKABLE QString qCreateAttributeString(TParameters const& attributes);

private:
    static std::vector<std::string> splitString(std::string const& text);
    static bool isAccessChar(char c);
};

#endif // USTRINGCONVERTER_H
