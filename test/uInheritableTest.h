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
};

#endif // UINHERITABLETEST_H
