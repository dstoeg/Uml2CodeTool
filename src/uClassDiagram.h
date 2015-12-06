#ifndef UCLASSDIAGRAM_H
#define UCLASSDIAGRAM_H

#include <QObject>

#include "uInheritable.h"

class uClassDiagram : public QObject
{
    Q_OBJECT
public:
    explicit uClassDiagram(QObject *parent = 0);
    void addClass(uInheritable * uClass);
    void removeClass(uInheritable * uClass);
    bool contains(uInheritable * uClass) const;
    uInheritable * find(std::string const& name) const;
    void applyVisitor(uVisitor* visitor);
    Q_INVOKABLE uInheritable * get(int index) const;
    Q_INVOKABLE int size() const;

private:
    TClasses mClasses;
};

#endif // UCLASSDIAGRAM_H
