#ifndef UINHERITABLETEST_H
#define UINHERITABLETEST_H

#include <QObject>
#include "src/uInheritable.h"

class uInheritableTest : public QObject
{
    Q_OBJECT
public:
    explicit uInheritableTest(QObject *parent = 0);

private:
    uInheritable * mObject;

private slots:
    void initTestCase();
    void cleanupTestCase();
    void getNameTest();
//    void getMethodsTest();
//    void getAttributesTest();
    void getReferencesTest();
    void getAccessTest();
    void setAccessTest();
//    void hasParentTest();

//    void addMethodTest();
//    void addAttributeTest();
//    void addReferenceTest();
};

#endif // UINHERITABLETEST_H
