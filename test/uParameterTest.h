#ifndef UPARAMETERTEST_H
#define UPARAMETERTEST_H

#include <QObject>
#include "src/uParameter.h"

class uParameterTest : public QObject
{
    Q_OBJECT
public:
    explicit uParameterTest(QObject *parent = 0);

private:
    uParameter * mParam;

private slots:
    void initTestCase();
    void cleanupTestCase();
    void getNameTest();
};

#endif // UPARAMETERTEST_H
