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
    void getDeclarationFileExtensionTest();
    void createDeclarationFileContentTest();
    void createImplementationFileContentTest();
    void hasSeparateFilesTest();
    void getLineCommentTest();
    void getNameTest();


private:
    uLanguageCPP * mObject;
};

#endif // ULANGUAGECPPTEST_H
