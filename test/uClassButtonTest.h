#ifndef UCLASSBUTTONTEST_H
#define UCLASSBUTTONTEST_H

#include <QObject>
#include "src/uClassButton.h"

class uClassButtonTest : public QObject
{
    Q_OBJECT
public:
    explicit uClassButtonTest(QObject *parent = 0);

private slots:
    void initTestCase();
    void cleanupTestCase();
    void getInstanceTest();
    void createTest();
//    void updateTest(uInheritable* inheritable);
//    void initializeBoxesTest();

private:
    uClassButton * mObject;
};

#endif // UCLASSBUTTONTEST_H
