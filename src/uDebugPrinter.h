#ifndef UDEBUGPRINTER_H
#define UDEBUGPRINTER_H

#include "uInheritable.h"
#include <string>
#include <QObject>
#include <QString>

class uDebugPrinter : public QObject
{
    Q_OBJECT
public:
    uDebugPrinter(QObject * parent = 0);
    Q_INVOKABLE static void printText(std::string const& text);
    Q_INVOKABLE static void qPrintText(QString const& text);
    Q_INVOKABLE static void printMethod(uMethod *method);
    Q_INVOKABLE static void printMethods(TMethods const& methods);
    Q_INVOKABLE static void printAttribute(uParameter *attribute);
    Q_INVOKABLE static void printAttributes(TParameters const& params);
    Q_INVOKABLE static void printClass(uInheritable * obj);

private:
    static void debug_print(std::string const& text);
};

#endif // UDEBUGPRINTER_H
