#ifndef UGRIDLAYOUT_H
#define UGRIDLAYOUT_H

#include <QObject>
#include <QString>
#include <vector>
#include "uGridObject.h"


class uGridLayout : public QObject
{
    Q_OBJECT
public:
    explicit uGridLayout(QObject *parent = 0);
    uGridLayout(int width, int height);

    Q_INVOKABLE bool addObject(int i, int j, int width, int height, QString const& name, int type);
    Q_INVOKABLE bool removeObject(QString const& name);
    Q_INVOKABLE bool removeObject(int i, int j);
    Q_INVOKABLE bool changeObjectName(QString const& name, const QString &newName);
    Q_INVOKABLE bool moveObject(const QString &name, int newX, int newY);

    Q_INVOKABLE QString getString(int x, int y) const;

    Q_INVOKABLE int getWidth() const;
    Q_INVOKABLE int getHeight() const;

    Q_INVOKABLE bool setWidth(int width);
    Q_INVOKABLE bool setHeight(int height);
    Q_INVOKABLE bool setPrinted(QString const& name);

    Q_INVOKABLE int getX(QString const& name) const;
    Q_INVOKABLE int getY(QString const& name) const;

    Q_INVOKABLE bool isEmpty(int x, int y) const;
    Q_INVOKABLE bool contains(QString const& name) const;

signals:

public slots:

private:
    int mWidth;
    int mHeight;
    TGridObject mTable;
    bool checkBounds(int i, int j, int width, int height) const;
    bool checkBounds(int i, int j) const;

};

#endif // UGRIDLAYOUT_H
