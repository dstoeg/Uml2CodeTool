#ifndef UVISITORTEST_H
#define UVISITORTEST_H

#include "src/uVisitor.h"
#include <QObject>

class uVisitorTest : public QObject
{
    Q_OBJECT
public:
    explicit uVisitorTest(QObject *parent = 0);

private slots:

private:
    uVisitor * mObject;
};

#endif // UVISITORTEST_H
