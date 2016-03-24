#ifndef UGRIDARROW_H
#define UGRIDARROW_H

#include "uGridObject.h"
#include "uGridSegment.h"

#include <QString>

class uGridClass;

enum uArrowType {
    uAggregation,
    uInheritance,
    uDependency
};

/**
 * @brief The uGridArrow class is a collection of uGridSegments that defines a relationship in the grid.
 *        This relationhip could be an aggregation, a dependence or an inheritance.
 *        Contains pointers to the two classes connected by the arrow.
 */

class uGridArrow
{
public:
    uGridArrow(const QString &origin, const QString &destination, int type, TGridSegment segments);
    uGridArrow(const QString &origin, const QString &destination, uArrowType type);
    //~uGridArrow();

    //Getters
    QString getOrigin() const;
    QString getDestination() const;
    int getSize() const;
    uGridSegment * getSegment(int index) const;
    TGridSegment getSegments() const;
    bool getDeleted() const;
    int getType() const;

    //Setters
    void addSegment(uGridSegment * segment);
    void setDeleted(bool del);
    void resizeX(double ratio, int destinationX, int destWidth);
    void resizeY(double ratio, int destinationY, int destHeight);

    bool equals(uGridArrow * arrow) const;
    bool equals(const QString &origin, const QString &destination, uArrowType type) const;
    int selected(int x, int y) const;

    //Manages the segment movements
    void moveSegments(int oldX, int oldY, int newX, int newY);
    bool notifyMovement(QString const &name, int movX, int movY);
//    void mergeSegments(); //called after each moveSegments to check possible segment merges

private:
    uArrowType mType;
    TGridSegment mSegments;
    QString mOrigin;
    QString mDestination;
    bool mDeleted;
    double mRatioXdest;
    double mRatioYdest;
    double mRatioXorigin;
    double mRatioYorigin;
    int mSegmentSelected;

    double distancePointToPoint(int x, int y, int i, int j) const;
};

typedef std::vector<uGridArrow*> TGridArrow;
typedef std::vector<uGridArrow*>::iterator TGridArrowIter;
typedef std::vector<uGridArrow*>::const_iterator TGridArrowConstIter;

#endif // UGRIDARROW_H
