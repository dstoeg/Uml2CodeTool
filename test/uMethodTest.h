#ifndef UMETHODTEST_H
#define UMETHODTEST_H

#include <QObject>
#include "src/uMethod.h"

class uMethodTest : public QObject
{
    Q_OBJECT
public:
    explicit uMethodTest(QObject *parent = 0);

private:
    uMethod * mMethod;

private slots:
    void initTestCase();
    void cleanupTestCase();
    void getNameTest();
    void getReturnTypeTest();
    void getAccessTest();
    void getParametersTest();
};

#endif // UMETHODTEST_H
