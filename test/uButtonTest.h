#ifndef UBUTTONTEST_H
#define UBUTTONTEST_H

#include <QObject>
#include "src/uButton.h"

class uButtonTest : public QObject
{
    Q_OBJECT
public:
    explicit uButtonTest(QObject *parent = 0);

private slots:
    void initTestCase();
    void cleanupTestCase();
    void getInstanceTest();
//    virtual void update(uInheritable* inheritable) {}
//    virtual uInheritable* create(uClassType type, uAccess access, std::string const& name, TParameters & attributes, TMethods & methods, TReferences & references, uInheritable *base) {}
//    virtual void initializeBoxes(){}

private:
    uButton * mObject;
};

#endif // UBUTTONTEST_H
