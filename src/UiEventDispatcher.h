#ifndef UIEVENTDISPATCHER_H
#define UIEVENTDISPATCHER_H

#include <QObject>
#include <QString>
#include "uStringConverter.h"
#include "uClassType.h"


class UiEventDispatcher : public QObject
{
    Q_OBJECT
public:
    explicit UiEventDispatcher(QObject *parent = 0);
    Q_INVOKABLE void createClass(QString name);
    Q_INVOKABLE void createClass(QString name, QString parent, QString methods, QString attributes);

    Q_INVOKABLE void setClassState(int type);

signals:

public slots:

private:
    uStringConverter mConverter;
    uClassType mSelectedClassState;

};

#endif // UIEVENTDISPATCHER_H
