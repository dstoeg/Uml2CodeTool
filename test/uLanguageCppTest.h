#ifndef ULANGUAGECPPTEST_H
#define ULANGUAGECPPTEST_H

#include <QObject>
#include "src/uLanguageCpp.h"

class uLanguageCppTest : public QObject
{
    Q_OBJECT
public:
    explicit uLanguageCppTest(QObject *parent = 0);

private slots:
    void initTestCase();
    void cleanupTestCase();

    void getImplementationFileExtensionTest();

private:
    uLanguageCPP * mObject;
};

#endif // ULANGUAGECPPTEST_H
