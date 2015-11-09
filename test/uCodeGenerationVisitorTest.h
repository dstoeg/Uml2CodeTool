#ifndef UCODEGENERATIONVISITORTEST_H
#define UCODEGENERATIONVISITORTEST_H

#include <QObject>
#include "src/uCodeGenerationVisitor.h"

class uCodeGenerationVisitorTest : public QObject
{
    Q_OBJECT
public:
    explicit uCodeGenerationVisitorTest(QObject *parent = 0);

private slots:
    void initTestCase();
    void cleanupTestCase();
    void setGetLanguageTest();

private:
    uCodeGenerationVisitor * mObject;
};

#endif // UCODEGENERATIONVISITORTEST_H
