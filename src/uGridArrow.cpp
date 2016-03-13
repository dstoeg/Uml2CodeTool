#include "uGridArrow.h"

uGridArrow::uGridArrow(QString const& origin, QString const& destination, int type, TGridSegment segments)
{
    mOrigin = origin;
    mDestination = destination;
    mSegments = segments;
    mType = uDependency;
    mDeleted = false;

    if(type == 0)
        mType = uInheritance;

    if(type == 1)
        mType = uAggregation;

}

uGridArrow::uGridArrow(QString const& origin, QString const& destination, uArrowType type)
{
    mOrigin = origin;
    mDestination = destination;
    mType = type;
    mDeleted = false;
}

QString uGridArrow::getOrigin() const
{
    return mOrigin;
}

QString uGridArrow::getDestination() const
{
    return mDestination;
}

int uGridArrow::getSize() const
{
    return mSegments.size();
}

uGridSegment *uGridArrow::getSegment(int index) const
{
    return mSegments[index];
}

bool uGridArrow::getDeleted() const
{
    return mDeleted;
}

int uGridArrow::getType() const
{
    if(mType == uInheritance)
        return 0;

    if(mType == uAggregation)
        return 1;

    return 2;
}

void uGridArrow::addSegment(uGridSegment *segment)
{
    return mSegments.push_back(segment);
}

void uGridArrow::setDeleted(bool del)
{
    mDeleted = del;
}

bool uGridArrow::equals(uGridArrow *arrow) const
{
    return arrow->mType == mType && arrow->mOrigin == mOrigin && arrow->mDestination == mDestination;
}

bool uGridArrow::equals(const QString &origin, const QString &destination, uArrowType type) const
{
    return mOrigin == origin && mDestination == destination && mType == type;
}

//uGridArrow::~uGridArrow()
//{
//    for(TGridObjectConstIter iter=mSegments.begin(); iter != m.end(); iter++)
//    {
//        ~(*iter);
//    }
//}

