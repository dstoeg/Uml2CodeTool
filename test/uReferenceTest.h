#ifndef UREFERENCETEST_H
#define UREFERENCETEST_H

#include "src/uReference.h"
#include <QObject>

class uReferenceTest : public QObject
{
    Q_OBJECT
public:
    explicit uReferenceTest(QObject *parent = 0);

private slots:
    void initTestCase();
    void cleanupTestCase();
    void getAccessTest();
    void getReferenceSymbolTest();
    void getClassTest();

private:
    uReference * mObject;
};

#endif // UREFERENCETEST_H
