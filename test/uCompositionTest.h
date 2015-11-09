#ifndef UCOMPOSITIONTEST_H
#define UCOMPOSITIONTEST_H

#include <QObject>
#include "src/uComposition.h"

class uCompositionTest : public QObject
{
    Q_OBJECT
public:
    explicit uCompositionTest(QObject *parent = 0);


private slots:
    void initTestCase();
    void cleanupTestCase();
    void getReferenceSymbolTest();

private:
    uComposition * mObject;
};

#endif // UCOMPOSITIONTEST_H
