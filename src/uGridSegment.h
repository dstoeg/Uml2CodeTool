#ifndef UGRIDSEGMENT_H
#define UGRIDSEGMENT_H

#include "uGridObject.h"
#include <QString>

class uGridSegment: public uGridObject
{
public:

    uGridSegment(int mX, int mY, int mX_to, int mY_to);
    virtual ~uGridSegment(){}

    virtual bool selected(int x, int y) const;

    bool pivoteMovement(int oldX, int oldY, int newX, int newY);

    int getLength() const;

    double getInclination() const;

};

typedef std::vector<uGridSegment*> TGridSegment;
typedef std::vector<uGridSegment*>::iterator TGridSegmentIter;
typedef std::vector<uGridSegment*>::const_iterator TGridSegmentConstIter;

#endif // UGRIDSEGMENT_H
