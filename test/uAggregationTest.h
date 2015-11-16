#ifndef UAGGREGATIONTEST_H
#define UAGGREGATIONTEST_H

#include "src/uAggregation.h"
#include <QObject>

class uAggregationTest : public QObject
{
    Q_OBJECT
public:
    explicit uAggregationTest(QObject *parent = 0);

private slots:
    void initTestCase();
    void cleanupTestCase();
    void getAccessTest();
    void getReferenceSymbolTest();
    void getClassTest();

private:
    uReference * mObject;
};

#endif // UAGGREGATIONTEST_H
