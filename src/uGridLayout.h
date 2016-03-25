#ifndef UGRIDLAYOUT_H
#define UGRIDLAYOUT_H

#include <QObject>
#include <QString>
#include <vector>
#include "uGridArrow.h"
#include "uGridClass.h"


class uGridLayout : public QObject
{
    Q_OBJECT
public:
    explicit uGridLayout(QObject *parent = 0);
    uGridLayout(int width, int height);

    Q_INVOKABLE bool addClass(int i, int j, int i_to, int j_to, QString const& name);
    Q_INVOKABLE bool removeObject(QString const& name);
    Q_INVOKABLE bool removeObject(int i, int j);
    Q_INVOKABLE bool changeObjectName(QString const& name, const QString &newName);
    Q_INVOKABLE bool moveObject(const QString &name, int movX, int movY);
    Q_INVOKABLE bool createAggregation(const QString &aggregationName, const QString &name);
    Q_INVOKABLE bool createInheritance(const QString &name, const QString &parent);

    Q_INVOKABLE int getAggregationIndex(const QString &name, const QString &reference) const;
    Q_INVOKABLE int getInheritanceIndex(const QString &name, const QString &reference) const;
    Q_INVOKABLE void addSegmentToArrow(int arrowIndex, int mX, int mY, int mWidth, int mHeight) const;
    Q_INVOKABLE void deleteNonExistentArrows();
    Q_INVOKABLE void setArrowsDeleted();

    Q_INVOKABLE QString getString(int x, int y) const;
    Q_INVOKABLE int getArrowSelected(int x, int y) const;
    Q_INVOKABLE void modifyArrow(int index, int oldX, int oldY, int newX, int newY);
//    Q_INVOKABLE void mergeSegments(int arrowIndex);

    Q_INVOKABLE int getWidth() const;
    Q_INVOKABLE int getHeight() const;
    Q_INVOKABLE int getArrowsSize() const;
    Q_INVOKABLE int getArrowSize(int index) const;
    Q_INVOKABLE int getArrowType(int index) const;

    Q_INVOKABLE bool setWidth(int width);
    Q_INVOKABLE bool setHeight(int height);

    Q_INVOKABLE int getClassX(QString const& name) const;
    Q_INVOKABLE int getClassY(QString const& name) const;
    Q_INVOKABLE int getClassX_to(QString const& name) const;
    Q_INVOKABLE int getClassY_to(QString const& name) const;
    Q_INVOKABLE int getClassWidth(QString const& name) const;
    Q_INVOKABLE int getClassHeight(QString const& name) const;

    Q_INVOKABLE int getSegmentX(int arrowIndex, int segIndex) const;
    Q_INVOKABLE int getSegmentY(int arrowIndex, int segIndex) const;
    Q_INVOKABLE int getSegmentX_to(int arrowIndex, int segIndex) const;
    Q_INVOKABLE int getSegmentY_to(int arrowIndex, int segIndex) const;
    Q_INVOKABLE int getSegmentWidth(int arrowIndex, int segIndex) const;
    Q_INVOKABLE int getSegmentHeight(int arrowIndex, int segIndex) const;
    Q_INVOKABLE int getSegmentLength(int arrowIndex, int segIndex) const;

    Q_INVOKABLE bool isEmpty(int x, int y) const;
    Q_INVOKABLE bool contains(QString const& name) const;

signals:

public slots:

private:
    int mWidth;
    int mHeight;
    TGridClass mTable;
    TGridArrow mArrows;
    TGridSegment mSegments;
    bool checkBounds(int i, int j, int width, int height) const;
    bool checkBounds(int i, int j) const;

};

#endif // UGRIDLAYOUT_H
