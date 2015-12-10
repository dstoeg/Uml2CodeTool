#ifndef UCLASSDIAGRAM_H
#define UCLASSDIAGRAM_H

#include <QObject>
#include "uInheritable.h"

class uClassDiagram : public QObject
{
    Q_OBJECT
public:
    static uClassDiagram &getInstance();
    //explicit uClassDiagram(QObject *parent = 0);
    Q_INVOKABLE void addClass(uInheritable * uClass);
    Q_INVOKABLE void removeClass(uInheritable * uClass);
    bool removeClass(QString const &name);
    Q_INVOKABLE bool contains(uInheritable * uClass) const;
    Q_INVOKABLE uInheritable * find(QString const& name) const;
    void applyVisitor(uVisitor* visitor);
    Q_INVOKABLE uInheritable * get(int index) const;
    Q_INVOKABLE int size() const;

private:
    TClasses mClasses;

protected:
    uClassDiagram(QObject * parent = 0);
    uClassDiagram(uClassDiagram const&);
    void operator = (uClassDiagram const&);
};



#endif // UCLASSDIAGRAM_H
