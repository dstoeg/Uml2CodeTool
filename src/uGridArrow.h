#ifndef UGRIDARROW_H
#define UGRIDARROW_H

#include "uGridObject.h"
#include "uGridSegment.h"

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
    uGridArrow(uGridClass * origin, uGridClass * destination, int type, TGridSegment segments);
    //~uGridArrow();

    //Getters
    uGridClass * getOrigin() const;
    uGridClass * getDestination() const;
    int getSize() const;
    uGridSegment * getSegment(int index);

    //Setters
    void addSegment(uGridSegment * segment);

    bool equals(uGridArrow * arrow) const;

private:
    uArrowType mType;
    TGridSegment mSegments;
    uGridClass * mOrigin;
    uGridClass * mDestination;
};

typedef std::vector<uGridArrow*> TGridArrow;
typedef std::vector<uGridArrow*>::iterator TGridArrowIter;
typedef std::vector<uGridArrow*>::const_iterator TGridArrowConstIter;

#endif // UGRIDARROW_H
