#ifndef UINTERFACEBUTTONTEST_H
#define UINTERFACEBUTTONTEST_H

#include <QObject>
#include "src/uInterfaceButton.h"

class uInterfaceButtonTest : public QObject
{
    Q_OBJECT
public:
    explicit uInterfaceButtonTest(QObject *parent = 0);

private slots:
    void initTestCase();
    void cleanupTestCase();
    void getInstanceTest();
    void createTest();
    //    void updateTest(uInheritable* inheritable);
    //    void initializeBoxesTest();

private:
    uInterfaceButton * mObject;
};

#endif // UINTERFACEBUTTONTEST_H
