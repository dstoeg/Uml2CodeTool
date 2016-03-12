#include "uGridArrow.h"

uGridArrow::uGridArrow(uGridClass *origin, uGridClass *destination, int type, TGridSegment segments)
{
    mOrigin = origin;
    mDestination = destination;
    mSegments = segments;
    mType = uDependency;

    if(type == 0)
        mType = uInheritance;

    if(type == 1)
        mType = uAggregation;

}

uGridClass *uGridArrow::getOrigin() const
{
    return mOrigin;
}

uGridClass *uGridArrow::getDestination() const
{
    return mDestination;
}

int uGridArrow::getSize() const
{
    return mSegments.size();
}

uGridSegment *uGridArrow::getSegment(int index)
{
    return mSegments[index];
}

void uGridArrow::addSegment(uGridSegment *segment)
{
    return mSegments.push_back(segment);
}

bool uGridArrow::equals(uGridArrow *arrow) const
{
    return arrow->mType == mType && arrow->mOrigin == mOrigin && arrow->mDestination == mDestination;
}

//uGridArrow::~uGridArrow()
//{
//    for(TGridObjectConstIter iter=mSegments.begin(); iter != m.end(); iter++)
//    {
//        ~(*iter);
//    }
//}

